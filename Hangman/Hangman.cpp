#include "Hangman.h"
#include <fstream>

Hangman::Hangman() {

	uint a;
	string file;
	cout << "Select difficulty : " << endl;
	cout << "1 - Easy" << endl;
	cout << "2 - Medium" << endl;
	cout << "3 - Hard" << endl;
	cin >> a;
	
	switch (a)
	{
	case Easy:
		difficulty = Easy;
		file = "easy.txt";
		break;
	case Medium:
		difficulty = Medium;
		file = "medium.txt";
		break;
	case Hard:
		difficulty = Hard;
		file = "hard.txt";
		break;
	default:
		difficulty = Hard;
		file = "hard.txt";
		break;
	}
	int random = rand() % 100;
	int i = 1;
	fstream read(file, ios::in);
	while (!read.eof())
	{
		read >> Word;
		if (i == random) {
			break;
		}
		i++;
	}
	read.close();

}
Hangman::Hangman(string word)
{
	difficulty = Custom;
	Word = word;
}
void Hangman::PrintHangman()
{
	switch (lives)
	{
	case 6:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 5:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 4:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 3:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 2:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|\\  |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 1:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|\\  |\n";
		shift(6); cout << "      /    |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 0:
		enter(6);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|\\  |\n";
		shift(6); cout << "      / \\  |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n";
		shift(6); cout << "     YOU LOST!";
		break;
	default:
		enter(6);
		shift(6); cout << "            \n";
		shift(6); cout << "            \n";
		shift(6); cout << "            \n";
		shift(6); cout << "            \n";
		shift(6); cout << "            \n";
		shift(6); cout << "            \n";
		shift(6); cout << "            \n\n";
		break;
	}
	
}

void Hangman::PrintWord()
{
	enter(1);
	shift(6);
	for (int i = 0; i < Word.size(); i++)
	{
		
		cout << " - ";
	}
	cout << endl;
}

void Hangman::Play()
{
	char current_guess;
	while (lives != 0)
	{
		system("cls");
		PrintHangman();
		PrintWord();
		cin >> current_guess;
		system("pause");
	}
	
}
