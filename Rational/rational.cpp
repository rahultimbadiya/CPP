#include<iostream>

#include"header.h"

using namespace std;

Rational::Rational()
{
	top = 0;
	bottom = 0;
}

Rational::Rational(int t)
{
	top = t;
	bottom = 1;
}

Rational::Rational(int t, int b)
{
	top = t;
	bottom = b;
	normalize();
}

Rational::Rational(const Rational & r1)
{
	
	top = r1.top;
	bottom = r1.bottom;
	
}

int Rational::numerator() const
{

	return top;
}

int Rational::denominator() const
{
	
	return bottom;
}
void Rational::operator =(const Rational r )
{
	top = r.top;
	bottom = r.bottom;
}

void Rational::normalize()
{
	int x, y,a,b;
	a = top;
	b = bottom;
	while(a!=0)
	{ 
		x = a;
		a = b%a;
		b = x;
	}
	 
	top = top / x;
	bottom = bottom / x;
	
	cout << "The normalize rational values are:" << top << "/" << bottom << endl;
	
}

Rational Rational:: operator +(const Rational r)
{
	if (bottom == r.bottom)
	{
		top = top + r.top;
		Rational c(top, bottom);
		return (c);
	}
	else
	{
		top = top*r.bottom + bottom*r.top;
		bottom = bottom*r.bottom;
		Rational c(top, bottom);
		return (c);
	}
	


}

Rational Rational::operator *(const Rational r)
{
	top = top*r.top;
	bottom = bottom*r.bottom;
	Rational c(top, bottom);
	return (c);

}
void Rational::read()
{

}

 ostream& operator <<( ostream& out, Rational& rational)
{
	int a = rational.numerator();
	int b = rational.denominator();
	out << a << "/" << b << endl;
	return(out);
 }
void Rational::display()
{
	cout << "Calculating the result:" <<top<<"/"<<bottom<< endl;
}

