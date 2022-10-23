#include "Hangman.h"
#include <stack>
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
	shift(5);
	cout << "        ";
	bool iss = false;
	int j = 0;
	for (int i = 0; i < Word.size(); i++)
	{
		
		iss = false;
		for (j = 0; j < Guessed.size(); j++)
		{
			if (Word[i] == Guessed[j]) {
				iss = true;
				break;
			}

		}
		if (iss) {
			cout << " " << Guessed[j] << " ";
		}
		else {
			cout << " _ ";
		}
		j = 0;
		
		
	}

	cout << endl;
}

void Hangman::Play()
{
	bool isGuessed = false;
	stack<char> guess;
	string current_guess;
	while (lives != 0 && isGuessed != true)
	{
		system("cls");

		PrintHangman();
		PrintWord();
		bool isRepeat = false;
		cout << "Enter a letter or a word to guess: ";
		cin >> current_guess;


		for (int i = 0; i < Guessed.size(); i++)
		{
			if (current_guess[0] == Guessed[i]) {
				lives--;
				isRepeat = true;
				break;
			}
		}

		if (current_guess.size() == Word.size()) {

			if (Word == current_guess) {
				Guessed = Word;
				isGuessed = true;
				system("cls");
				PrintHangman();
				PrintWord();
				cout << "\nYOU WON!";
				system("pause");
			}
			else {
				lives--;
			}
		}
		else if (current_guess.size() == 1 && isRepeat != true) {
			bool temp = false;
			for (int i = 0; i < Word.size(); i++)
			{
				if (Word[i] == current_guess[0]) {
					Guessed += current_guess;
					temp = true;
					break;
				}
				
			}
			if (temp == false)lives--;
		}
		else {
			cout << "Wrong input";
		}
		
		cout << Word << endl;
		cout << Guessed.size() << endl;
		cout << Guessed << endl;


	}
	
}
