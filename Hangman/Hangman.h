#pragma once
#include <iostream>
#define shift(x) for (int i = 0; i < x; i++) { cout << "\t"; } //Макрос для табуляций
#define enter(x) for(int i = 0; i < x; i++){cout << "\n";}  //Макрос для переноса строки

typedef unsigned int uint;
enum Difficulty { Easy = 1, Medium, Hard, Custom};

using namespace std;

class Hangman
{
	string Word;
	string Guessed;
	uint lives = 6;
	Difficulty difficulty = Custom;

public:
	Hangman();
	Hangman(string word);
	void PrintHangman();
	void PrintWord();
	void Play();
};

