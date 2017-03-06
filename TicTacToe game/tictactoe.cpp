#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include"link.h"
#include"deck.h"
#include"tictaactoe.h"
#pragma once
using namespace std;


//default constructor
tictactoe::tictactoe()
{
	
}
//starts the game by taking the input from the players
void tictactoe::start_game()
{
	int ch, position, k=0,l=0;
	tictactoe t;
	char sym1, sym2;
	string n1, n2;
	n1 = player1.getname();
	n2 = player2.getname();
	sym1 = player1.getsymbol();
	sym2 = player2.getsymbol();
	cout << "\nDecide who makes first move:\n1-" << n1 << "\t2-" << n2<<endl;
	cin >> ch;
	if (ch == 1)
	{
	//if player 1 is playing first then this part will be executed
		for (int i = 0;i < 5;i++)
		{
			system("CLS");
			deck::printdeck();
			cout << "\n"<<n1<<" enter your move";
			position = getPlayerMove();
			node::append(position);
			deck::setinput(position, sym1);			
			deck::input1(position);
			k = isGameOver();
			if (k == 1)
			{
				system("CLS");
				deck::printdeck();
				cout << n1<<" wins";
				printresult();
				system("pause");
				break;
			}
			l=isDraw();
			if (l == 1)
			{
				cout << "Gmae Draw...";
				printresult();
				system("pause");
				break;
			}
			system("CLS");
			deck::printdeck();
			cout << n2<<" enter your move";
			position = getPlayerMove();
			node::append(position);
			deck::setinput(position, sym2);			
			deck::input2(position);
			k = isGameOver();
			if (k == 1)
			{
				system("CLS");
				deck::printdeck();
				cout << n2<<" wins";
				printresult();
				system("pause");
				break;
			}
			l = isDraw();
			if (l == 1)
			{
				cout << "Gmae Draw...";
				printresult();
				system("pause");
				break;
			}
			system("CLS");
		}
	}
	else
	{
		//if player 2 is playing first then this part will be executed
		for (int i = 0;i < 5;i++)
		{
			system("CLS");
			deck::printdeck();
			cout << "\n"<<n2<<"enter your move";
			position = getPlayerMove();
			node::append(position);
			deck::setinput(position, sym2);			
			deck::input2(position);
			k = isGameOver();
			if (k == 1)
			{
				system("CLS");
				deck::printdeck();
				cout << n2<<" wins";
				printresult();
				system("pause");
				break;
			}
			l = isDraw();
			if (l == 1)
			{
				cout << "Gmae Draw...";
				printresult();
				system("pause");
				break;
			}
			system("CLS");
			deck::printdeck();						
			cout << "\n"<<n1<<"enter your move";
			position = getPlayerMove();
			node::append(position);
			deck::setinput(position, sym1);
			deck::input1(position);
			k = isGameOver();
			if (k == 1)
			{
				
				system("CLS");
				deck::printdeck();				
				cout << n1<<" wins";
				printresult();
				system("pause");
				break;
			}
			l = isDraw();
			if (l == 1)
			{
				cout << "Gmae Draw...";
				printresult();
				system("pause");
				break;
			}

			deck::input1(position);
			system("CLS");
			
		}
	}

}
//takes the position from the player
int tictactoe::getPlayerMove()
{
	int pos;
	cin >> pos;
	pos=validatePlayerInput(pos);
	return(pos);
}
//check if the player has selected valid position or not its range is from 1 to 9
int tictactoe::validatePlayerInput(int pos)
{
	if (pos>10 || pos<0)
	{
		cout << "\nEnter valid input.....";
		getPlayerMove();
	}
	pos=validateMove(pos);
	return(pos);
	
}
//checks if the position requested by player is free or not
int tictactoe::validateMove(int pos)
{
	int valu = node::check(pos);
	if (valu == 1)
	{
		cout << "position already taken please select another position\n";
		pos=getPlayerMove();
		return(pos);
	}
	return(pos);
}
//checks if any player is already winner or not
int tictactoe::isGameOver()
{	
	int k;
	k= deck::checkgame();
	if (k == 1)
	{
		node::savetofile();
	}
	return(k);
}
//checks if no player is winning and all the positions are full
int tictactoe::isDraw()
{
	int k = deck::checkdraw();
	if (k == 1)
	{
		return(1);
	}
	else
	{ return(2); }
}
void tictactoe::printresult()
{
	cout << "\n Score of " << player1.getname() << " is " << player1.getscore();
	
	cout << "\n Score of " << player2.getname() << " is " << player2.getscore();

}
istream & operator>>(istream & in, tictactoe & t)
{
	string n1,n2;
	char s1,s2;
	cout << "\nPlayer 1 :";
	cout << "\nEnter name:";in >> n1;
	cout << "Enter Symbol: ";in >> s1;
	cout << "\nPlayer 2 :";
	cout << "\nEnter name:";in >> n2;
	cout << "Enter Symbol: ";in >> s2;
	t.player1=t.setplayer1(n1, s1);
	t.player2=t.setplayer2(n2, s2);
	return(in);
}
//setup an instance of members os class player in tictactoe class
player tictactoe::setplayer1(string n, char s)
{
	player p(n, s);
	return(p);
}
player tictactoe::setplayer2(string n, char s)
{
	player p(n, s);
	return(p);
}

