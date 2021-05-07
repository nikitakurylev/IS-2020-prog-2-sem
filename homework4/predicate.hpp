#ifndef PREDICATE_H
#define PREDICATE_H
#include <iterator>
#include <iostream>
using namespace std;

template<class T1, class T2>
bool allOf(T1 begin, T1 end, T2 comp) {
	while (begin != end) {
		if (!comp(*begin))
			return false;
		++begin;
	}
	return true;
}

template<class T1, class T2>
bool anyOf(T1 begin, T1 end, T2 comp) {
	while (begin != end) {
		if (comp(*begin))
			return true;
		++begin;
	}
	return false;
}

template<class T1, class T2>
bool noneOf(T1 begin, T1 end, T2 comp) {
	while (begin != end) {
		if (comp(*begin))
			return false;
		++begin;
	}
	return true;
}

template<class T1, class T2>
bool oneOf(T1 begin, T1 end, T2 comp) {
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

template<class T1, class T2>
bool isPartitioned(T1 begin, T1 end, T2 comp) {
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

template<class T1, class T2>
T1 findNot(T1 begin, T1 end, T2 a) {
	while (begin != end) {
		if (*begin != a)
			break;
		++begin;
	}
	return begin;
}

template<class T1, class T2>
T1 findBackward(T1 begin, T1 end, T2 a) {
    T1 result = end;
	while (begin != end) {
		if (*begin == a)
			result = begin;
		++begin;
	}
	return result;
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