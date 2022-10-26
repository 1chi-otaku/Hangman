#pragma once
#include <iostream>
#include "Message.h"
#define shift(x) for (int i = 0; i < x; i++) { cout << "\t"; } //Macro fot \t
#define enter(x) for(int i = 0; i < x; i++){cout << "\n";}  //Macro for \n

typedef unsigned int uint;
enum Difficulty { Easy = 1, Medium, Hard, Custom};
using namespace std;

class Hangman
{
	string Word;									//Word to find.
	string Guessed;									//String Guessed contains all the corect guesess.
	string Guessed_all;								//String Guessed_all containt all the guesess.
	string file;									//String file contains the path to the file

	uint lives = 6;									//default amount of lives in Hagman is 6.
	Difficulty difficulty = Custom;					//enum contains int constant according to difficulty.

	Message mess;									//Object of class Message. Prints, depending on the success of the player, either inspiring or erroneous messages.	
public:
	Hangman();
	Hangman(string word);
	void PrintHangman()const;						//Prints Hagman depending on lives.
	void PrintTried()const;							//Prints all the letters user tried to input.
	void PrintTime(int time_in_seconds)const;		//Prints time via chrono library.
	void CalculatePoint(int time_in_seconds);		//Calculates player's points depending on time, difficulty of word,lives.
	void GenerateWord();							//Generates the word from text file.
	void Play();									//Game engine.
	void Reset();									//Resets all the var.. so player can start game again.
	int SetDiffuclty();								//Sets difficulty of game.
	bool PrintWord()const;							//Prints guessed word, returns true if the word is complete!
};

