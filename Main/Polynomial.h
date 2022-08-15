#pragma once
#include <iostream>
#include <cassert>
	using namespace std;

class Polynomial
{

private:

	const static int SIZE = 1000;
	static int degreeArr[SIZE];
	static int _size;
	int static maxDegree;

	int degree;
	double coeff[100] = { 0 };

public:

	Polynomial();
	Polynomial(int);
	Polynomial(const double*, int);

	void print();

	//gets
	int getDegree(bool)const;
	int static getMaxDegree();
	double getCoeff(int)const;

	//sets
	void setCoeff(int, double);
	void setDegree(int);

	//operators
	void operator +(const Polynomial&);
	friend ostream& operator <<(ostream& , const Polynomial&);
};


