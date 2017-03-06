#include <iostream>
#include"money.h";
using namespace std;

Money::Money()
{
	Get_dollars();
	Get_cents();

}

Money::Money(int x, int y)
{
	dollars = x;
	cents = y;
}
Money::Money(double xyz)
{
	
	dollars = GetDollarsPart(xyz);
	cents = GetCentsParts(xyz);
}
void Money :: set_dollars(int x1)
{
	dollars = x1;
}
void Money::Get_dollars()
{
	int a1;
	cout << "Enter value of dollar:" << endl;
	cin >> a1;
	set_dollars(a1);
}
void Money::set_cents(int mycents)
{
	cents = mycents;
}
void Money::Get_cents()
{
	int a1;
	cout << "Enter value of cents:" << endl;
	cin >> a1;
	set_cents(a1);
}
int Money::GetDollarsPart(double am)
{
	return(am / 1);
}
int Money::GetCentsParts(double am)
{
	am = am * 100;
	return((int)am % 100);
}

void Money::print()
{
	cout << "The amount is  " << dollars<<"."<<cents<<endl;
}
Money Money:: operator +(const Money &rhs)const
{
	int val1 = dollars + rhs.dollars;
	int val2 = cents + rhs.cents;
	if (val2 > 99)
	{
		val2 = val2 - 100;
		val1 = val1 + 1;

	}
	return (Money(val1, val2));
}

Money operator - (const Money & lhs, const Money & rhs)
{
	if (lhs.cents < rhs.cents)
	{
		if (lhs.dollars < rhs.dollars)
		{
			return (0, 0);
		}
		else
		{
			int val1 = (lhs.dollars - 1) - (rhs.dollars);
			int val2 = (lhs.cents + 100) - (rhs.cents);
			return(Money(val1, val2));

		}
	}
	else
	{
		int val1 = lhs.dollars - rhs.dollars;
		int val2 = lhs.cents - rhs.cents;
		return (Money(val1, val2));
	}
}

bool operator == (const Money & lhs, const Money & rhs)
{
	if (lhs.dollars == rhs.dollars)
	{
		if (lhs.cents == rhs.cents)
		{
			return(true);
		}
		else
		{
			return (false);
		}
	}
	else
	{
		return (false);
	}
}

std::ostream & operator <<(std::ostream & myoutputStream, Money & m)
{
	myoutputStream << m.dollars << "." << m.cents;
	return (myoutputStream);

}

std::istream & operator >>(std::istream & myinputstream, Money & m)
{
	return(myinputstream);

}