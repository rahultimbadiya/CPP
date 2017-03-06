#include<iostream>
using namespace std;
#include"money.h"

Money::Money(int a, int b)
{
	dollars = a;
	cents = b;
		
}

Money::Money(int a)
{
	dollars = a;
	cents = 0;

}

void Money::display()
{
	if (cents < 10)
	{
		cout << "The price is $" << dollars << ".0" << cents<<endl;
	}else
	{
		cout << "The price is $" << dollars << "." << cents<<endl;
	}
	
}
 void Money::change()
{
	int quarter = 0, dime = 0, nickel = 0, pennies = 0;
	int change = cents;
	quarter = change / 25;
	change = change % 25;
	dime = change / 10;
	change = change % 10;
	nickel = change / 5;
	change = change % 5;
	cout << "Change for " << cents << " is" << quarter << "-quarters," << dime << "-dimes," << nickel << "-nickel," <<pennies << "-cents.\n";


}

 Money Money::add(Money a)
 {
	 int c1 = (dollars * 100) + cents;
	 int c2 = (a.dollars * 100) + a.cents;
	 int c3, c4, c5;
	 c3 = c1 + c2;
	 c4 = c3 / 100;
	 c5 = c4 % 100;
	 Money m3(c4,c5);
	 return m3;
	 
 }

 
 Money Money::sub(Money a)
 {
	 int c1 = (dollars * 100) + cents;
	 int c2 = (a.dollars * 100) + a.cents;
	 int c3,c4,c5;
	 if (c1 < c2)
	 {
		 cout<<"invalid operation";
		 Money m3(0, 0);
		 return m3;
	 }
	 else
	 {
		 c3 = c1 - c2;
		 c4 = c3 / 100;
		 c5 = c3 % 100;
		 Money m3(c4,c5);
		 return m3;

	 }
 }

 void Money::is_equal(Money a)
 {
	 if (dollars == a.dollars)
	 {
		 if (cents == a.cents)
		 {
			 cout << "The value are equals" << endl;
		 }
		 else
		 {
			 cout << "valu are not equal" << endl;
		 }
	 }
	 else
	 {
		 cout << "No match found" << endl;
	 }
 }

 Money Money::saletax(int a)
 {
	 int change = (dollars * 100) + cents;
	 int c1, c2, c3, c4;
	 c1 = (change * 6) / 100;
	 c2 = (change * 6) % 100;
	 if (c2 > 5)
	 {
		 c1 = c1 + 1;

	 }
	 c3 = c1 / 100;
	 c4 = c1 % 100;
	 Money m3(c3, c4);
	 return m3;
 }