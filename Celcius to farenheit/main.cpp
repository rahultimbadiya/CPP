#include<iostream>
using namespace std;
void main()
{
	double cd, fd;
	cout << "Enter the celcius temperature:";
	cin >> cd;
	fd = (9 * cd) / 5 + 32.0;
	cout << "farenheit:" << fd<<endl;
	getchar();
}