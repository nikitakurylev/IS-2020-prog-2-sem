#ifndef PREDICATE_H
#define PREDICATE_H
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

bool allOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	while (begin != end) {
		if (!comp(*begin))
			return false;
		++begin;
	}
	return true;
}

bool anyOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	while (begin != end) {
		if (comp(*begin))
			return true;
		++begin;
	}
	return false;
}

bool noneOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	while (begin != end) {
		if (comp(*begin))
			return false;
		++begin;
	}
	return true;
}

bool oneOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	bool result = false;
	while (begin != end) {
		if (comp(*begin)) {
			if (result)
				return false;
			else
				result = true;
		}
		++begin;
	}
	return result;
}

template<class T1, class T2>
bool isSorted(T1 begin, T1 end, T2 comp) {
	while (begin + 1 != end) {
		if (!comp(*begin, *(begin + 1)))
			return false;
		++begin;
	}
	return true;
}
template<class T1>
bool isSorted(T1 begin, T1 end) {
	while (begin + 1 != end) {
		if (*begin > *(begin + 1))
			return false;
		++begin;
	}
	return true;
}

bool isPartitioned(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	bool result = false;
	while (begin + 1 != end) {
		if (comp(*begin) != comp(*(begin + 1))) {
			if (result)
				return false;
			else
				result = true;
		}
		++begin;
	}
	return result;
}

vector<int>::iterator findNot(vector<int>::iterator begin, vector<int>::iterator end, int a) {
	while (begin != end) {
		if (*begin != a)
			break;
		++begin;
	}
	return begin;
}

vector<int>::iterator findBackward(vector<int>::iterator begin, vector<int>::iterator end, int a) {
    vector<int>::iterator finish = end;
	while (begin != end) {
		if (*end == a)
	        return end;
		--end;
	}
	return finish;
}

template<class T1, class T2>
bool isPalindrome(T1 begin, T1 end, T2 comp){
    --end;
	while (distance(begin, end) > 0) {
		if (!comp(*begin, *end))
			return false;
		++begin;
		--end;
	}
	return true;
}
#endif