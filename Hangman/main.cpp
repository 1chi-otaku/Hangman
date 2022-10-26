#include <iostream>
#include <Windows.h>
#include "Hangman.h"
using namespace std;

HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);

void PrintMenu();

int main() {
	srand(time(NULL));

	
	Hangman obj;

	int input = 1;
	while (input != 0)
	{
		system("cls");
		PrintMenu();
		cin >> input;
		switch (input)
		{
		case 1:
			system("cls");

			while (input != 2)
			{
				obj.Play();
				cout << "Play Again?" << endl;
				cout << "1 - YES" << endl;
				cout << "2 - NO" << endl;
				cin >> input;
				system("cls");
			}
			break;
			
		case 2:
			system("cls");
			obj.SetDiffuclty();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	

	return 0;
}

void PrintMenu()
{
	system("cls");
	SetConsoleTextAttribute(m, 4);
	shift(4); cout << "                                                         " << endl;
	shift(4); cout << "    #########                                            " << endl;
	SetConsoleTextAttribute(m, 2);
	shift(4); cout << "    #       #                                            " << endl;
	SetConsoleTextAttribute(m, 6);
	shift(4); cout << "    #       0                                            " << endl;
	SetConsoleTextAttribute(m, 1);
	shift(4); cout << "    #      /|\\                                          " << endl;
	SetConsoleTextAttribute(m, 5);
	shift(4); cout << "    #      / \\                                          " << endl;
	SetConsoleTextAttribute(m, 4);
	shift(4); cout << "    #             #  #  ##  # #     #   #  ##  # #      " << endl;
	shift(4); cout << "    #             #### #__# #\\#     ## ## #__# #\\#    " << endl;
	shift(4); cout << "    #             #  # #  # # # ___ # # # #  # # #      " << endl;
	SetConsoleTextAttribute(m, 8);
	shift(4); cout << " ########                                                 " << endl;
	shift(4); cout << " #      #                                                 " << endl << endl << endl;
	SetConsoleTextAttribute(m, 15);

	shift(6); cout << "1. Play" << endl;
	shift(6); cout << "2. Choose difficulty" << endl;
	shift(6); cout << "0. Exit" << endl;
	cout << "|-|:";
}	
