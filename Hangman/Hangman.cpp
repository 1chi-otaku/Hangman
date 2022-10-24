#include "Hangman.h"
#include <stack>
#include <fstream>
#include <Windows.h>
#include <chrono>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

Hangman::Hangman() = default;

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
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 4);
		printf("%c ", 3);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 5:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 4);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 9);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 4:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 4);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 9);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 3:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 9);
		printf("%c ", 3);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|   |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 2:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 9);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 8);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|\\  |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 1:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 9);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 8);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
		shift(6); cout << "       +---+\n";
		shift(6); cout << "       |   |\n";
		shift(6); cout << "       0   |\n";
		shift(6); cout << "      /|\\  |\n";
		shift(6); cout << "      /    |\n";
		shift(6); cout << "           |\n";
		shift(6); cout << "     =========\n\n";
		break;
	case 0:
		enter(2);
		shift(9);
		SetConsoleTextAttribute(h, 8);
		printf("%c ", 3);
		printf("%c ", 3);
		printf("%c ", 3);
		SetConsoleTextAttribute(h, 15);
		enter(4);
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

void Hangman::PrintTried()
{
	for (int i = 0; i < Guessed_all.size(); i++)
	{
		SetConsoleTextAttribute(h, 15);
		if (i != 0) cout << ",";

		SetConsoleTextAttribute(h, 12);
		for (int j = 0; j < Guessed.size(); j++)
		{
			if (Guessed_all[i] == Guessed[j]) {
			SetConsoleTextAttribute(h, 10);
			}
		}
		cout << Guessed_all[i];
	}
	SetConsoleTextAttribute(h, 15);
	if(Guessed_all.size() != 0)cout << ".";
	cout << endl;
}

void Hangman::PrintTime(int time_in_seconds)
{
	int sec = time_in_seconds, min = 0;
	
	while (sec >= 60)
	{
		sec -= 60;
		min++;
	}

	cout << min << ":" << sec << endl;
}

void Hangman::CalculatePoint(int time_in_seconds)
{

	int time_bonus = 0,guessed_bonus, live_bonus;
	if (lives != 0) {
		if (time_in_seconds <= 15) time_bonus = 520;
		else if (time_in_seconds <= 20) time_bonus = 400;
		else if (time_in_seconds <= 30) time_bonus = 250;
		else if (time_in_seconds <= 40) time_bonus = 130;
		else if (time_in_seconds <= 60) time_bonus = 70;
	}
	
	guessed_bonus = Guessed.size() * 50;
	live_bonus = lives * 30;

	cout << "Time - "; PrintTime(time_in_seconds);
	cout << "Word - " << Word << endl;
	cout << "Tries - " << Guessed_all.size() << endl;
	cout << "Lives - " << lives << endl;
	PrintTried();
	enter(5);
	Sleep(200);
	shift(6);
	cout << "  TIME   BONUS  " << time_bonus << endl;
	Sleep(200);
	shift(6);
	cout << "  WORD   BONUS  " << guessed_bonus << endl;
	Sleep(200);
	shift(6);
	cout << "  LIVE   BONUS  " << live_bonus << endl << endl;
	Sleep(180);

	shift(6);
	int total = time_bonus + guessed_bonus + live_bonus;
	cout << "  TOTAL  " << total << endl << endl;
	Sleep(200);

	if (total >= 1100) {
		SetConsoleTextAttribute(h, 14);
		shift(6); cout << "     ##########   " << endl;
		shift(6); cout << "    ##        ##  " << endl;
		shift(6); cout << "    #          #   " << endl;
		shift(6); cout << "    ##             " << endl;
		shift(6); cout << "     ##########    " << endl;
		shift(6); cout << "              ##   " << endl;
		shift(6); cout << "    #          #   " << endl;
		shift(6); cout << "    ##       ##   " << endl;
		shift(6); cout << "     ######### " << endl;
		SetConsoleTextAttribute(h, 15);
	}
	else if (total >= 900) {
		SetConsoleTextAttribute(h, 11);
		shift(6); cout << "        ##       " << endl;
		shift(6); cout << "     ##    ##    " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    ##########   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		SetConsoleTextAttribute(h, 15);
	}
	else if (total >= 700) {
		SetConsoleTextAttribute(h, 12);
		shift(6); cout << "    #########    " << endl;
		shift(6); cout << "    #        #    " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #########    " << endl;
		shift(6); cout << "    #        #    " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "    #########    " << endl;
		SetConsoleTextAttribute(h, 15);
	}
	else if (total >= 550) {
		SetConsoleTextAttribute(h, 8);
		shift(6); cout << "      #######    " << endl;
		shift(6); cout << "    #        #    " << endl;
		shift(6); cout << "    #        #  " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    #              " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    #        #  " << endl;
		shift(6); cout << "    #        #   " << endl;
		shift(6); cout << "     ########    " << endl;
		SetConsoleTextAttribute(h, 15);
	}
	else {
		SetConsoleTextAttribute(h, 6);
		shift(6); cout << "    ##########  " << endl;
		shift(6); cout << "    #             " << endl;
		shift(6); cout << "    #           " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    ##########    " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    #           " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    ##########  " << endl;
		SetConsoleTextAttribute(h, 15);
	}


}

void Hangman::GenerateWord()
{
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


void Hangman::Play()
{
	Word.clear();
	Guessed.clear();
	Guessed_all.clear();
	GenerateWord();
	lives = 6;


	int elapsed_time_ms = 0;
	bool isGuessed = false;
	string current_guess;
	string message;
	auto t_start = std::chrono::high_resolution_clock::now();
	while (lives != 0 && isGuessed != true)
	{ 
		system("cls");
		PrintHangman();
		PrintWord();
		PrintTried();
		shift(5);
		cout << "   " << message << endl;
		message = "";
		cout << "Enter a letter or a word to guess: ";
		cin >> current_guess;
		
		if (Word == current_guess) {
			Guessed = Word;
			isGuessed = true;
			system("cls");
			PrintHangman();
			PrintWord();
			shift(5);
			cout << "YOU WIN!" << endl;
			auto t_end = std::chrono::high_resolution_clock::now();
			elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
			shift(5);
			system("pause");
		}
		else if (current_guess.size() == 1) {
			bool temp = false;
			bool isGuessedLetter = false;
			bool isTriedLetter = false;

			for (int i = 0; i < Guessed.size(); i++)
			{
				if (current_guess[0] == Guessed[i]) {
					message = "You've guessed this letter already.";
					isGuessedLetter = true;
					break;
				}
			}
			if (!isGuessedLetter) {
				for (int i = 0; i < Guessed_all.size(); i++)
				{
					if (current_guess[0] == Guessed_all[i]) {
						isTriedLetter = true;
						message = "You've tried this letter already.";
					}
				}
				if (!isTriedLetter) {
					Guessed_all += current_guess;
				}
			}
	
			for (int i = 0; i < Word.size(); i++)
			{
				if (Word[i] == current_guess[0]) {
					Guessed += current_guess;
					temp = true;
					break;
				}
				
			}
			if (temp == false && !isTriedLetter)lives--;
		}
		else {
			message = "Wrong input";
			lives--;
		}
		
	}
	system("cls");
	CalculatePoint((elapsed_time_ms/1000));
	
}
