#pragma once
#include <iterator>

template <typename T>
class CircularBuffer {
public:
	struct Iterator
	{
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;  // or also value_type*
		using reference = T&;  // or also value_type&

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		// Prefix increment
		Iterator& operator++() { m_ptr++; return *this; }

		// Postfix increment
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

		friend Iterator& operator- (const Iterator& a, const Iterator& b) { return Iterator(a.m_ptr - b.m_ptr); };

	private:
		pointer m_ptr;
	};

	CircularBuffer() {
	};
	CircularBuffer(int count) : size(count) {
		buffer = new T[size];
	}
	Iterator begin() const {
		return Iterator(&buffer[0]);
	}
	Iterator end() const {
		return Iterator(&buffer[size - 1]);
	}
	T first() {
		return buffer[bstart];
	}
	T last() {
		return buffer[bend];
	}
	void addFirst(T value) {
		bstart = (size + bstart - 1) % bstart;
		buffer[bstart] = value;
	}
	void delFirst() {
		buffer[bstart] = 0;
		bstart = (bstart + 1) % bstart;
	}
	void addLast(T value) {
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
		T* newbuffer = new T[newsize];
		for (int i = 0; i < min(size, newsize); i++) {
			newbuffer[i] = buffer[i];
		}
		delete[] buffer;
		buffer = newbuffer;
	}

private:
	int size, bstart, bend;
	T* buffer;
};