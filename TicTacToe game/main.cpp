//BY: Ketul Patel	ID:1002032
//BY: Rahul Timbadiya  ID:1002119

#include<iostream>
#include<string>
#include<stdio.h>
#include"player.h"
#include"tictaactoe.h"
#include"deck.h"
#pragma once
using namespace std;

int main()
{
	tictactoe t;
	cin >> t;		//overload >> operator
	deck d;
	d.printdeck();
	t.start_game();

	system("pause");
}