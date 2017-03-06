#include<iostream>
using namespace std;
#include"money.h"

int main()
{
	Money m1(17, 45), m2(7, 55);
	Money m3(0), m4(66), m5(22);
	
	m1.display();
	m2.display();
	m3.display();
	m4.display();

	

	m2.change();
	m3 = m1.saletax(6);
	m3.display();
	
	m3.is_equal(m5);

	m3 = m1.add(m2);
	m3.display();

    m3 = m1.sub(m2);
	m3.display();
	
	cout << "Program over \n";
	system("pause");
	return 0;
}