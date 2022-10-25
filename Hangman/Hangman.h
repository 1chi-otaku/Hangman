﻿#pragma once
#include <iostream>
#include "Message.h"
#define shift(x) for (int i = 0; i < x; i++) { cout << "\t"; } //Макрос для табуляций
#define enter(x) for(int i = 0; i < x; i++){cout << "\n";}  //Макрос для переноса строки

typedef unsigned int uint;
enum Difficulty { Easy = 1, Medium, Hard, Custom};

using namespace std;

class Hangman
{
	string Word;
	string Guessed;
	string Guessed_all;
	string file;

	uint lives = 6;
	Difficulty difficulty = Custom;

	Message mess;
	
public:
	Hangman();
	Hangman(string word);
	void PrintHangman()const;
	void PrintTried()const;
	void PrintTime(int time_in_seconds)const;
	void CalculatePoint(int time_in_seconds);
	void GenerateWord();
	void Play();
	void Reset();
	int SetDiffuclty();
	bool PrintWord()const;
};

