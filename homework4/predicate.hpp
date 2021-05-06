#pragma once
#include <iterator>
#include <vector>
using namespace std;

bool allOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));