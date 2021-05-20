#ifndef PREDICATE_H
#define PREDICATE_H
#include <iterator>
//fixed without std
//fixed T1 and T2 are bad names
//fixed isSorted should use default tempalte argument std::less
template<class TIterator, class TComparator>
bool allOf(TIterator begin, TIterator end, TComparator comp) {
	while (begin != end) {
		if (!comp(*begin))
			return false;
		++begin;
	}
	return true;
}

template<class TIterator, class TComparator>
bool anyOf(TIterator begin, TIterator end, TComparator comp) {
	while (begin != end) {
		if (comp(*begin))
			return true;
		++begin;
	}
	return false;
}

template<class TIterator, class TComparator>
bool noneOf(TIterator begin, TIterator end, TComparator comp) {
	while (begin != end) {
		if (comp(*begin))
			return false;
		++begin;
	}
	return true;
}

template<class TIterator, class TComparator>
bool oneOf(TIterator begin, TIterator end, TComparator comp) {
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


template<class TIterator, class TComparator = std::less<>>
bool isSorted(TIterator begin, TIterator end, TComparator comp = TComparator()) {
	while (begin + 1 != end) {
		if (!comp(*begin, *(begin + 1)))
			return false;
		++begin;
	}
	return true;
}

template<class TIterator, class TComparator>
bool isPartitioned(TIterator begin, TIterator end, TComparator comp) {
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

template<class TIterator, class TComparator>
TIterator findNot(TIterator begin, TIterator end, TComparator a) {
	while (begin != end) {
		if (*begin != a)
			break;
		++begin;
	}
	return begin;
}

template<class TIterator, class TComparator>
TIterator findBackward(TIterator begin, TIterator end, TComparator a) {
    TIterator result = end;
	while (begin != end) {
		if (*begin == a)
			result = begin;
		++begin;
	}
	return result;
}

template<class TIterator, class TComparator>
bool isPalindrome(TIterator begin, TIterator end, TComparator comp){
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