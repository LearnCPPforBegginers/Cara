#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double var1, var2;
	char op;
	bool repeat = true;
	while (repeat)//return point if player choose to restart
	{
		system("cls");// clears the screen
		cout << "Enter your operation. eg:1+2\n";
		cin >> var1 >> op >> var2;
		system("cls");
		switch (op)
		{
		case '+':
			cout << "=" << (var1 + var2) << endl;
			break;
		case '-':
			cout << "=" << (var1 - var2) << endl;
			break;
		case '*':
			cout << "=" << (var1 * var2) << endl;
			break;
		case '/':
			if (var2 != 0)
				cout << "=" << (var1 / var2) << endl;
			else
				cout << "You cannot divide by '0'\n";
			break;
		case '=':
			cout << "Character must be something like '+' , '-' , '*' , '/'" << endl;
			break;
		default:
			cout << "Wrong character!! Try eg:1+1" << endl;
		}
		char ask;
		cout << "Do you want to make another operation?(y/n)\n";//ask player if wants to do another operation
		cin >> ask;
		if (ask == 'y' || ask == 'Y')
			repeat = true;
		else
			repeat = false;
		{

		}
	}
    return 0;
}

