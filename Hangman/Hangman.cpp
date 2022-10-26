#include "Hangman.h"
#include <fstream>
#include <Windows.h>
#include <chrono>
#include "Message.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Hangman::Hangman() = default;

Hangman::Hangman(string word)
{
	difficulty = Custom;
	Word = word;
}
void Hangman::PrintHangman()const
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

		break;
		
	}
}
bool Hangman::PrintWord()const
{											
	enter(1);						//Align a word in the console based on its length.
	if (Word.size() <= 5) {
		cout << "\b\b\b\b";
	}
	if (Word.size() < 6)
		shift(1);
	if (Word.size() < 10) {
		shift(1);
	}
	if (Word.size() > 12) {										
		cout << "\b\b\b";
	}

	shift(4);
	cout << "       ";

	bool isGuesed = false;
	bool notfull = true;
	int j = 0;
	for (int i = 0; i < Word.size(); i++)
	{
		isGuesed = false;
		for (j = 0; j < Guessed.size(); j++)
		{
			if (Word[i] == Guessed[j]) {
				isGuesed = true;
				break;
			}

		}
		if (isGuesed) {
			cout << " " << Guessed[j] << " ";
		}
		else {
			notfull = false;
			cout << " _ ";
		}
		j = 0;
	}
	cout << endl;
	return notfull;
}
void Hangman::PrintTried()const
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
void Hangman::PrintTime(int time_in_seconds)const
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
	Sleep(300);

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
		shift(6); cout << "    #########    " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    #           " << endl;
		shift(6); cout << "    #            " << endl;
		shift(6); cout << "    ##########            " << endl;
		SetConsoleTextAttribute(h, 15);
	}
}
int Hangman::SetDiffuclty()
{
	uint input;
	cout << "Select difficulty : " << endl;
	cout << "1 - Easy" << endl;
	cout << "2 - Medium" << endl;
	cout << "3 - Hard" << endl;
	cout << "4 - Custom" << endl;
	cin >> input;

	switch (input)
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
	case Custom:
		difficulty = Custom;
		cout << "Enter the word: " << endl;
		file = "";
		cin >> Word;
		return 0;
	default:
		difficulty = Hard;
		file = "hard.txt";
		break;
	}
	
	return 0;
}
void Hangman::GenerateWord()
{
	int random = rand() % 151;								//Each file contains exactly 150 words, so i considered there is no reason to calculate amount of words in file with cycle.
	int i = 1;												//Sets an itterator to i to check if the random value and i matches.
	fstream read(file, ios::in);							//Opens file for reading.
	while (!read.eof())
	{
		read >> Word;										//Reads a word to Word field.
		if (i == random) {									//If a random value matches with i, breaks.
			break;
		}
		i++;
	}
	read.close();											//Closes the file.
}

void Hangman::Play()
{
	Reset();																				//Resets stats of player to start a new game.

	if (difficulty == Custom)																//If difficulty is custom, request a change in difficulty.
		SetDiffuclty();	
	if (difficulty != Custom)																//If difficulty is custom, the word won't be generated automatically so player can play with his word.
		GenerateWord();

	int elapsed_time_ms = 0;																//Variable for elapsed time in ms to use the chrono library, which counts time.
	bool isGuessed = false;																	//Bool variable that defines whether the word is guessed or not.
	string current_guess;																	//String val. to input guess. String value can provide an opportunity to input by one letter or full word.
	auto t_start = std::chrono::high_resolution_clock::now();			//t_start is a var from <chrono> library, using method now of class high_resolution_clock, we start counting from this point in time.

	while (lives != 0)																		//The game begins until lives > 0
	{ 
		if (PrintWord()) {																	//PrintWord() returns true only if the entire word is guessed. In this case, the game ends with the player's victory.
			system("cls");
			PrintHangman();
			PrintWord();
			shift(5);
			cout << "YOU WON!" << endl;
			auto t_end = std::chrono::high_resolution_clock::now();			//t_end is a var from <chrono> library, using method now of class high_resolution_clock, we stoped counting from this point in time.
			elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();   //Subtracts the start time from the end of time and returns it in milliseconds.
			system("pause");
			break;
		}

		system("cls");
		PrintHangman();																		//Prints the game field after the player's guess if the game is still in proccess.
		PrintWord();
		PrintTried();

		shift(5);
		mess.Print();																		//Prints, depending on the success of the player, either inspiring or erroneous messages.
		cout << "Enter a letter or a word to guess: ";
		cin >> current_guess;																//Guess input.
		if (Word == current_guess) {														//If current_guess contains search word, player gains a victory.
			isGuessed = true;
			Guessed = Word;																	
			system("cls");
			PrintHangman();
			PrintWord();
			shift(5);
			cout << "YOU WON!" << endl; 
			auto t_end = std::chrono::high_resolution_clock::now();          //t_end is a var from <chrono> library, using method now of class high_resolution_clock, we stoped counting from this point in time.
			elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();   //Subtracts the start time from the end of time and returns it in milliseconds.
			shift(5);
			system("pause");
			break;
		}
		else if (current_guess.size() == 1) {														//If input contains only 1 symbol.
			bool isSuccessLetter = false;															//Returns true, if the letter is not repeated and it is contained in the word.
			bool isGuessedLetter = false;															//Returns true, if the letter is repeated and it is contained in the word.
			bool isTriedLetter = false;																//Returns true, if the letter is repeated and it is not contained in the word.

			for (int i = 0; i < Guessed.size(); i++)												//Checks if the letter is already guessed.
			{
				if (current_guess[0] == Guessed[i]) {												//If the first element of guess is equal to Guessed string[i]:
					mess.SetMessage("You've guessed this letter already.");				//Puts a respective message in class Message.
					isGuessedLetter = true;															//Sets isGuessedLetter to true.
				}
			}
			if (!isGuessedLetter) {																	//If the guessed letter is not equal to Guessed letters:
				for (int i = 0; i < Guessed_all.size(); i++)										//Checks if the letter contains in all the letter player tried.
				{
					if (current_guess[0] == Guessed_all[i]) {										//If the first element of guess if equal to Guessed_all element.
						isTriedLetter = true;														//Sets isTriedLetter to true.
						mess.SetMessage("You've tried this letter already.");				//Puts a respective message in class Message.
					}
				}
				if (!isTriedLetter && !isGuessedLetter) {											//If the letter is not contained in any of the guessed or tried strings - arrays:
					Guessed_all += current_guess;													//Puts a current guess to a string array with all tried letters.
				}
			}
			for (int i = 0; i < Word.size(); i++)													//Checks if the letter is not repeated and if it matches with letter in search word.
			{
				if (Word[i] == current_guess[0] && !isTriedLetter && !isGuessedLetter) {			//If it matches, player guessed a new letter.
					mess.AddStreak();																//Adds streak to print an inspiring message to player.
					Guessed += current_guess;														//Adds a current guess to all the guessed string.
					isSuccessLetter = true;															//Sets is SuccessLetter to trie.
					break;
				}
			}
			if (isSuccessLetter == false && !isTriedLetter && !isGuessedLetter) {					//If the current attempt isn't successful, and the current letter does not repeat with the guessed and attempts, then the player guessed the wrong letter.
				lives--;																			//Decrements lives.
				mess.SetMessage("");												     	//Puts a respective message in class Message.
			}
		}
		else {
			mess.SetMessage("Wrong Input");												//If the input isn't the search words, and size of inputr is > 1 or 1<, it means plater wrote the wrong input. Puts a respective message in a Message class.
			lives--;																				//Decrements lives.
		}
		
	}
	if (lives == 0) {																				//Checks lives is 0, which means the player lost.
		system("cls");
		PrintHangman();																				//Prints a dead hangman.
		cout << endl;
		PrintWord();																				//Prints a current guessed word.
		system("pause");
		auto t_end = std::chrono::high_resolution_clock::now();				//t_end is a var from <chrono> library, using method now of class high_resolution_clock, we stoped counting from this point in time.
		elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();		//Subtracts the start time from the end of time and returns it in milliseconds.
	}
	system("cls");
	CalculatePoint((elapsed_time_ms/1000));											// Passes the elapsed time in (ms / 1000) to the CalculatePoints method, thus passing how long the player guessed the word in seconds. Method CalcilatePoint() calculates how many points player got and prints his rank.
		
}
void Hangman::Reset() //Resets stats of player to start a new game.
{
	Word.clear();				
	Guessed.clear();
	Guessed_all.clear();
	GenerateWord();
	lives = 6;
	mess.Clear();
}
