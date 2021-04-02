#include "polynomial.h"
#include <math.h>

void Polynomial::Build(int minPower, int maxPower, int* factorsArray) {
	min = minPower;
	max = maxPower;
	int count = max - min + 1;
	factors = new int[count];
	for (int i = 0; i < count; i++)
		factors[i] = factorsArray[i];
}

Polynomial::Polynomial(const Polynomial& other) {
	Build(other.min, other.max, other.factors);
}

Polynomial::~Polynomial() {
	delete[] factors;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
	if (this != &other)
		Build(other.min, other.max, other.factors);
	return *this;
}

//fixed return int
int Polynomial::operator[](int idx) const {
	if (idx<min || idx > max)
		return 0;
	return factors[idx - min];
}
int& Polynomial::operator[](int idx) {
	if (idx < min || idx > max)
	{
		int newmax = max, newmin = min;
		if (idx < min)
			newmin = idx;
		else if (idx > max)
			newmax = idx;
		int count = newmax - newmin + 1;
		int* newfactors = new int[count];
		for (int i = 0; i < count; i++) {
			newfactors[i] = 0;
			if (i + newmin >= min && i + newmin <= max)
				newfactors[i] = factors[i + newmin - min];
		}
		delete[] factors;
		max = newmax;
		min = newmin;
		factors = newfactors;
	}
	return factors[idx - min];
}

const Polynomial operator-(const Polynomial& obj) {
	return obj * (-1);
}

//fixed const bool ???
bool operator==(const Polynomial& left, const Polynomial& right)
{
	int min = std::min(left.min, right.min);
	int max = std::max(left.max, right.max);
	for (int i = min; i <= max; i++)
		if (left[i] != right[i])
			return false;
	return true;
}

const Polynomial operator*(const Polynomial& left, const Polynomial& right) {
	int min = left.min + right.min;
	int max = left.max + right.max;
	int count = max - min + 1;
	int* factors = new int[count];
	for (int i = 0; i < count; i++)
		factors[i] = 0;
	for (int i = left.min; i <= left.max; i++)
		for (int j = right.min; j <= right.max; j++)
			factors[i + j - min] += left[i] * right[j];
	return Polynomial(min, max, factors);
}


const Polynomial operator+(const Polynomial& left, const Polynomial& right) {
	int min = std::min(left.min, right.min);
	int max = std::max(left.max, right.max);
	int* factors = new int[max - min + 1];
	for (int i = min; i <= max; i++)
		factors[i - min] = left[i] + right[i];
	return Polynomial(min, max, factors);
}

//fixed int not const int&
const Polynomial operator*(const Polynomial& left, int right) {
	int count = left.max - left.min + 1;
	int* factors = new int[count];
	for (int i = 0; i < count; i++)
		factors[i] = left.factors[i]*right;
	return Polynomial(left.min, left.max, factors);
}

const Polynomial operator/(const Polynomial& left, const int right) {
	int count = left.max - left.min + 1;
	int* factors = new int[count];
	for (int i = 0; i < count; i++)
		factors[i] = left.factors[i] / right;
	return Polynomial(left.min, left.max, factors);
}

const Polynomial operator*(const int left, const Polynomial& right) {
	return right * left;
}

//fixed what???

std::ostream& operator<<(std::ostream& os, const Polynomial& obj){
	if (obj.max - obj.min == 0 && obj.factors[0] == 0) {
		os << "0";
		return os;
	}
	int start = obj.max - obj.min;
	for (int i = start; i >= 0; i--)
		if (obj.factors[i] != 0) {
			if(obj.factors[i]==-1)
				os << "-";
			else if (i != start && obj.factors[i] > 0)
				os << "+";
			int power = i + obj.min;
			if (abs(obj.factors[i]) != 1 || power == 0)
				os << obj.factors[i];
			if (power != 0) {
				os << "x";
				if (power != 1)
					os << "^" << power;
			}
		}
	return os;
}

//fixed O(n)
double Polynomial::get(int x) {
	double result = 0;
	double xpow = pow(x, min);
	for (int i = 0; i <= max - min; i++) {
		result += double(factors[i]) * xpow;
		xpow *= x;
	}
	return result;
}
