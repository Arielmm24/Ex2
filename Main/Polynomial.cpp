#include "Polynomial.h"
#include<array>

int Polynomial::degreeArr[] = { 0 };
int Polynomial::_size = 0;
int Polynomial::maxDegree = 0;

Polynomial::Polynomial()
{
	degree = 0;
	degreeArr[_size++] = this->degree;
	
}

Polynomial::Polynomial(int degree)
{
	this->degree = degree;
	degreeArr[_size++] = this->degree;
	
}

Polynomial::Polynomial(const double* coeffArr, int degree)
{
	this->degree = degree;
	//int arrSize = sizeof(coeffArr);
	for (int i = 0; i <= degree ;i++)//&& i <= arrSize; i++)
	{
		setCoeff(i, coeffArr[i]);
	}
	degreeArr[_size++] = this->degree;
	
}

void Polynomial::setCoeff(int degree, double coeff)
{
	this->coeff[degree] = coeff;
	if (this->coeff[degree] != 0 && degree > 0 && degree>maxDegree)
	{
		//maxDegree++;
		maxDegree = degree;
	}
}

void Polynomial::setDegree(int d)
{
	this->degree = d;
}

double Polynomial::getCoeff(int degree)const
{
	if (degree <= this->degree)
	{
		return this->coeff[degree];
	}
	else
	{
		return 0.0;
	}

}

int Polynomial::getDegree(bool what)const
{
	if (what == false)
	{
		return this->degree;
	}
	int i = degree + 1;
	return i;
}

void Polynomial::print()
{
	//cout << degree << endl << endl;
	int degTemp = degree;
	cout << "Polynomial= ";
	if (degree == 0)
	{
		cout << 0;
	}
	else {
		while (coeff[degTemp] == 0)
		{
			degTemp--;
		}
		degTemp++;
		cout << coeff[0];
		for (int i = 1; i < degTemp; i++)
		{
			cout << "+" << coeff[i] << "x" << "^" << i;
		}
	}
		cout << endl;

}

int Polynomial::getMaxDegree()
{
	return maxDegree;
}

void Polynomial::operator +(const Polynomial& p1) {
	int small, big ,flag=0;
	//double result;
	Polynomial result;
	if (this->getDegree(true) > p1.getDegree(true))
	{
		big = this->getDegree(true);
		small = p1.degree;
		flag = 1;               // flag=1 --> this.degree   Bigger
	}
	else
	{
		big = p1.degree;
		small = this->getDegree(true);          // flag=0 --> p1.degree   Bigger
	}
	result.setDegree(big);
	for (int i = 0; i < small + 1; i++)
	{
		result.setCoeff(i, this->getCoeff(i) + p1.getCoeff(i));
	}
	cout << "result" << endl;
	result.print(); //"big = " << big << "  small = " << small << endl;
	
}

ostream& operator <<(ostream& out, const Polynomial& p) {
	out << "Polynomial: ";
	int degTemp = p.degree;
	while (p.coeff[degTemp] == 0)
	{
		degTemp--;
	}
	degTemp++;
	out << p.coeff[0];
	for (int i = 1; i < degTemp; i++)
	{
		out << "+" <<"("<< p.coeff[i]<<")" << "x" << "^" << i;
	}
	out << endl;
		return out;
}
