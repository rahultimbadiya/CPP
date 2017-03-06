#pragma once
#include"deck.h"
#include<iostream>
using namespace std;

//creates memory for board
deck::deck()
{
	for (int i = 0;i < 3;i++)
	{
		a[i] = new char [3];
	}
	a[0][0] = '1';	a[0][1] = '2';	a[0][2] = '3';
	a[1][0] = '4';	a[1][1] = '5';	a[1][2] = '6';
	a[2][0] = '7';	a[2][1] = '8';	a[2][2] = '9';
	
}
//prints board
void deck::printdeck()
{
	cout <<"\n-------------------------------------------------- ";
	cout << "\n|\t" << a[0][0] << "\t|\t" << a[0][1] << "\t|\t" << a[0][2] << "\t|";
	cout << "\n------------------------------------------------- ";
	cout << "\n|\t" << a[1][0] << "\t|\t" << a[1][1] << "\t|\t" << a[1][2] << "\t|";
	cout << "\n------------------------------------------------- ";
	cout << "\n|\t" << a[2][0] << "\t|\t" << a[2][1] << "\t|\t" << a[2][2] << "\t|";
	cout << "\n------------------------------------------------- \n";
}

void deck::input1(int n)
{
	player1.push(n);
}
void deck::input2(int n)
{
	player2.push(n);
}
void deck::setinput(int pos, char sym)
{
	int i, j;
	if (pos == 1)
	{
		i = 0;j = 0;
		
	}
	else if (pos == 2)
	{
		i = 0;j = 1;

	}
	else if (pos == 3)
	{
		i = 0;j = 2;
	}
	else if (pos == 4)
	{
		i = 1;j = 0;
	}
	else if (pos == 5)
	{
		i = 1;j = 1;
	}
	else if (pos == 6)
	{
		i = 1;j = 2;
	}
	else if (pos == 7)
	{
		i = 2;j = 0;
	}
	else if (pos == 8)
	{
		i = 2;j = 1;
	}
	else
	{
		i = 2;j = 2;
			}
	a[i][j] = sym;
}
//checks the winng conditions is satisfied or not
int deck::checkgame()
{
	if( ( a[0][0] == a[0][1] && a[0][1] == a[0][2]) 
		|| (a[0][0] == a[1][0] && a[1][0] == a[2][0]) 
		|| (a[1][0] == a[1][1] && a[1][1] == a[1][2])
		||(a[2][0] == a[2][1] && a[2][1] == a[2][2])
		||(a[0][1] == a[1][1] && a[1][1] == a[2][1])
		||(a[0][2] == a[1][2] && a[1][2] == a[2][2])
		||(a[0][0] == a[1][1] && a[1][1] == a[2][2])
		||(a[0][2] == a[1][1] && a[1][1] == a[2][0]))
	{
		return(1);
	}
		
	else
	{
		return(2);
	}
}
//checks if all the positions are full or not
int deck::checkdraw()
{
	if (
		a[0][0] != '1' &&
		a[0][1] != '2' &&
		a[0][2] != '3' &&
		a[1][0] != '4' &&
		a[1][1] != '5' &&
		a[1][2] != '6' &&
		a[2][0] != '7' &&
		a[2][1] != '8' &&
		a[2][2] != '9')
	{
		return(1);
	}
		
	else
	{
		return(2);
	}
}