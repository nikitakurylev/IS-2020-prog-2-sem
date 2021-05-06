#ifndef PREDICATE_H
#define PREDICATE_H
#include <iterator>
#include <vector>
using namespace std;

bool allOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));
bool anyOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));
bool noneOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));
bool oneOf(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));
bool isSorted(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int, int));
bool isPartitioned(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int));
int findNot(vector<int>::iterator begin, vector<int>::iterator end, int a);
int findBackward(vector<int>::iterator begin, vector<int>::iterator end, int a);
bool isPalindrome(vector<int>::iterator begin, vector<int>::iterator end, bool comp(int, int));
#endif