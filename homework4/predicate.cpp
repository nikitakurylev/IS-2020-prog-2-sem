#include "predicate.hpp"
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

bool isSorted(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int, int)) {
	while (begin + 1 != end) {
		if (!comp(*begin, *(begin + 1)))
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

int findNot(vector<int>::iterator begin, vector<int>::iterator end, int a) {
	while (begin != end) {
		if (*begin == a)
			break;
		++begin;
	}
	return begin;
}

int findBackward(vector<int>::iterator begin, vector<int>::iterator end, int a) {
	while (begin != end) {
		if (*end == a)
			break;
		--end;
	}
	return end;
}

bool isPalindrome(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int, int)) {
	while (begin < end) {
		if (!comp(*begin, *end))
			return false;
		++begin;
		--end;
	}
	return true;
}