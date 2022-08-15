#include "Rational.h"


Rational::Rational()
{
	//this->denom.setDegree(2);
	this->denom=1;
	this->nom = 0;
}

Rational::Rational(const Polynomial& P1, const Polynomial& P2)
{
	this->nom = P1;
	this->denom = P2;
}

//gets
Polynomial Rational::getNom()
{
	return nom;
}

Polynomial Rational::getDenom()
{
	return denom;
}

void Rational::print()
{
	nom.print();
	cout << "--------------------------" << endl;
	/*if (denom.getDegree(true) == 0 && nom.getDegree(false) == 0)
	{
		cout << "1";
	}*/
	if (this->denom.getDegree(false) == 1)
	{
		cout<<"Polynomial: "<<"1"<<endl;
	}
	else 
	{
		denom.print();
	}
}