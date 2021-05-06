#include "predicate.hpp"
bool allOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int)) {
	while (begin != end) {
		if (!comp(*begin))
			return false;
		++begin;
	}
	return  true;
}