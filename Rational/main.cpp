#include<iostream>
#include"header.h"

using namespace std;

void main()
{

	Rational p(3,4), q(2,3), r(2,5), t, u;
	
	t = p + q;
	u = q * r;
	t.display();
	cout << "After operator overloading:"<<t;
	u.display();
	cout <<"After operator overloading:"<< u;
	system("pause");

}