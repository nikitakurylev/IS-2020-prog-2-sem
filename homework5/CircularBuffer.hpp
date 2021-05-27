#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <iterator>
#include <stdexcept>
#include <iostream>
using namespace std;
template <typename bufferType>
class CircularBuffer {
public:
	struct Iterator
	{
	public:
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = bufferType;
		using pointer = bufferType*;
		using reference = bufferType&;
		
		Iterator(pointer ptr) : m_ptr(ptr) {}
		Iterator(pointer ptr, pointer begin, pointer end) : m_ptr(ptr), bbegin(begin), bend(end) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		Iterator& operator++() {
			if(m_ptr == bend)
				m_ptr = bbegin;
			else
				m_ptr++; 
			return *this; 
		}
		Iterator operator++(int) {
			Iterator tmp = *this;
			++(*this);
			return tmp;
		}
		Iterator& operator--() { 
			if(m_ptr == bbegin)
				m_ptr = bend;
			else
				m_ptr--; 
			return *this; 
		}
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
		pointer bbegin;
		pointer bend;
	};

	CircularBuffer(int count) : size(count+1) {
		buffer = new bufferType[size];
		bstart = 1;
		bend = 0;
		cursize = 0;
	}

	~CircularBuffer() {
		delete[] buffer;
	}

	Iterator begin() const {
		return Iterator(&buffer[bstart], &buffer[0], &buffer[size - 1]);
	}
	Iterator end() const {
		return Iterator(&buffer[(bend + 1) % size], &buffer[0], &buffer[size - 1]);
	}
	bufferType first() {
		return buffer[bstart];
	}
	bufferType last() {
		return buffer[bend];
	}
	void addFirst(bufferType value) {
		bstart = (size + bstart - 1) % size;
		buffer[bstart] = value;
		if(cursize < size-1)
			cursize++;
		else
			bend = (size + bend - 1) % size;
	}
	void delFirst() {
		buffer[bstart] = 0;
		bstart = (bstart + 1) % size;
		cursize--;
	}
	void addLast(bufferType value) {
		bend = (bend + 1) % size;
		buffer[bend] = value;
		if(cursize < size-1)
			cursize++;
		else
			bstart = (bstart + 1) % size;
	}
	void delLast() {
		buffer[bend] = 0;
		bend = (size + bend - 1) % size;
		cursize--;
	}
	int operator[](int i) const {
		if (i < 0 || i >= cursize)
			throw out_of_range("Out of range");
		return buffer[(bstart + i) % size];
	}

	int& operator[](int i) {
		if (i < 0 || i >= cursize)
			throw out_of_range("Out of range");
		return buffer[(bstart + i) % size];
	}

	void changeCapacity(int newsize) {
		newsize++;
		bufferType* newbuffer = new bufferType[newsize];
		for (int i = 0; i < min(size, newsize); i++) {
			newbuffer[i] = buffer[(bstart + i) % size];
		}
		delete[] buffer;
		buffer = newbuffer;
		if(size < newsize)
			size = newsize;
		bstart = 0;
		bend = bstart + cursize - 1;
	}

private:
	int size, bstart, bend, cursize;
	bufferType* buffer;
};
#endif