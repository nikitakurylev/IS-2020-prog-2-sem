#pragma once
#include <iterator>

template <typename bufferType>
class CircularBuffer {
public:
	struct Iterator
	{
	public:
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = bufferType;
		using pointer = bufferType*;  // or also value_type*
		using reference = bufferType&;  // or also value_type&

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		Iterator& operator++() { m_ptr++; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		Iterator& operator--() { m_ptr--; return *this; }
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

		template<typename nType>
		Iterator& operator+=(nType n) {
			difference_type m = n;
			if (m >= 0) while (m--) ++*this;
			else while (m++) --*this;
			return *this;
		}

		template<typename nType>
		friend Iterator operator+(const Iterator& a, nType n) {
			Iterator temp = a;
			return temp += n;
		}
		template<typename nType>
		friend Iterator operator+(nType n, const Iterator& a) {
			return a + n;
		}
		template<typename nType>
		Iterator& operator-=(nType n) {
			return *this += -n;
		}
		template<typename nType>
		friend Iterator operator-(const Iterator& a, nType n) {
			Iterator temp = a;
			return temp -= n;
		}
		friend long long operator-(const Iterator& a, const Iterator& b) {
			return b.m_ptr - a.m_ptr;
		}
		template<typename nType>
		reference operator[](nType n) const {
			return *(this + n);
		}
		friend bool operator< (const Iterator& a, const Iterator& b) { return b - a > 0; };
		friend bool operator> (const Iterator& a, const Iterator& b) { return b < a; };
		friend bool operator>= (const Iterator& a, const Iterator& b) { return !(a < b); };
		friend bool operator<= (const Iterator& a, const Iterator& b) { return !(a > b); };


	private:
		pointer m_ptr;
	};

	CircularBuffer(int count) : size(count) {
		buffer = new bufferType[size];
	}

	~CircularBuffer() {
		delete[] buffer;
	}

	Iterator begin() const {
		return Iterator(&buffer[0]);
	}
	Iterator end() const {
		return Iterator(&buffer[size - 1]);
	}
	bufferType first() {
		return buffer[bstart];
	}
	bufferType last() {
		return buffer[bend];
	}
	void addFirst(bufferType value) {
		bstart = (size + bstart - 1) % bstart;
		buffer[bstart] = value;
	}
	void delFirst() {
		buffer[bstart] = 0;
		bstart = (bstart + 1) % bstart;
	}
	void addLast(bufferType value) {
		bend = (bend + 1) % bstart;
		buffer[bstart] = value;
	}
	void delLast() {
		buffer[bstart] = 0;
		bend = (size + bend - 1) % bstart;
	}
	int operator[](int i) const {
		if (i < 0 || i >= size)
			throw exception("Out of range");
		return buffer[i];
	}

	int& operator[](int i) {
		if (i < 0 || i >= size)
			throw exception("Out of range");
		return buffer[i];
	}

	void changeCapacity(int newsize) {
		bufferType* newbuffer = new bufferType[newsize];
		for (int i = 0; i < min(size, newsize); i++) {
			newbuffer[i] = buffer[i];
		}
		delete[] buffer;
		buffer = newbuffer;
	}

private:
	int size, bstart, bend;
	bufferType* buffer;
};