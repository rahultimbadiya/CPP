#include<iostream>
#include<string>
#include<stdio.h>
#include"player.h"
#pragma once
using namespace std;

player::player()
{
	name = "";
	symbol = ' ';
	win = 0;
	lose = 0;
	draw = 0;
}

player::player(string n, char s)
{
	name = n;
	symbol = s;
}

int player::getscore()
{
//	return((w * 2) + d - l);
	return(0);
}
ostream & operator<<(ostream & out, player & p)
{
	return(out << "\nName =" << p.name << "\t\tSymbol = " << p.symbol << "\tScore = " << p.getscore());
}
char player::getsymbol()
{
	return(symbol);
}
string player::getname()
{
	return(name);
}
int player::getwin()
{
	return(win);
}
int player::getdraw()
{
	return(draw);
}
int player::getlose()
{
	return(lose);
}