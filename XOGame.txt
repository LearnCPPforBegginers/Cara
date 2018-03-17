#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	char xyCoord[3][3];
	char value = '1';
	int i = 2;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			xyCoord[x][y] = value++;
		}
	}
	while (true)
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				cout.width(5);
				cout << xyCoord[x][y];
			}
			cout << endl << endl;
		}

		int xCoord, yCoord, xoSwitch;
		cout << "X coord: ";
		cin >> xCoord;
		cout << "Y coord: ";
		cin >> yCoord;
		if (((xCoord >= 1) && (xCoord <= 3))&&((yCoord >= 1) && (yCoord <= 3)))
		{
			if ((xyCoord[xCoord - 1][yCoord - 1] != 'X') && (xyCoord[xCoord - 1][yCoord - 1] != 'O'))
			{
				if (i % 2 == 0)
				{
					xyCoord[xCoord - 1][yCoord - 1] = 'X';
					i = 1;
				}
				else
				{
					xyCoord[xCoord - 1][yCoord - 1] = 'O';
					i = 2;
				}
				system("cls");
			}
			else
			{
				system("cls");
				cout << "These coordinates are already assigned "<<endl;
			}
		}
		else
		{
			system("cls");
			cout << "ERROR invalid coordinates insert a value between 1-3" << endl;
		}
	}
	return 0;
}

