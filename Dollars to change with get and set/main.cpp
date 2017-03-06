#include<iostream>
#include"money.h";

using namespace std;

int main() {
	Money m1;
	double myinput;
	/*cout<<"Enter the dollars and cents"<<endl;
	cin>>myinput;*/
	Money m2(4.5);
	/*cout<<"Enter the dollars and cents"<<endl;
	cin>>myinput;*/
	Money m3(5.75);
	Money m4 = m2 + m3;
	Money m6 = m2 - m3;
	m2.print();
	m3.print();
	m4.print();
	m6.print();
	cout <<" The overload function value  "<<m4<<endl;
	int check = m2 == m3;
	if (check == 1)
	{
		cout << "Values are same" << endl;

	}
	else
	{
		cout << "Values are not same" << endl;
	}

	Money m5;
	cin >> m5;
	cout << m5 << endl;
	
	m5.print();
	
	system("pause");
	return 0;
}