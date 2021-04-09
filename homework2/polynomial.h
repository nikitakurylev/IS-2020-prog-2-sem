#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
public:
	Polynomial(int minPower, int maxPower, int* factorsArray)
		: min(minPower)
		, max(maxPower)
		, factors(factorsArray)
	{}
	Polynomial()
		: min(0)
		, max(0)
		, factors(new int[1]{ 0 })
	{}

	Polynomial(const Polynomial& other);
	virtual ~Polynomial();
	virtual Polynomial& operator= (const Polynomial& other);
	virtual Polynomial& operator+=(const Polynomial& other);
	virtual Polynomial& operator-=(const Polynomial& other);
	virtual Polynomial& operator*=(const int other);
	virtual Polynomial& operator/=(const int other);

	int operator[](int idx) const;
	int& operator[](int idx);
	friend const Polynomial operator-(const Polynomial& obj);

	friend bool operator==(const Polynomial& left, const Polynomial& right);

	friend const Polynomial operator*(const Polynomial& left, const Polynomial& right);
	//fixed + from +=
	friend const Polynomial operator+(const Polynomial& left, const Polynomial& right);
	friend const Polynomial operator-(const Polynomial& left, const Polynomial& right);
	friend const Polynomial operator*(const Polynomial& left, const int right);
	friend const Polynomial operator/(const Polynomial& left, const int right);
	friend const Polynomial operator*(const int left, const Polynomial& right);

	friend std::ostream& operator<<(std::ostream& os, const Polynomial& obj);

	double get(int x);

private:
	int min, max;
	int* factors;
	void Build(int minPower, int maxPower, int* factorsArray);
};
#endif