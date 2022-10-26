#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Message{
	string message;										//Message itself.
	unsigned int streak;								//Depending on current streak, prints inspiring messages.
public:
	Message() {
		message = "";
		streak = 0;
	}
	Message(string new_message) {
		message = new_message;
		streak = 0;
	}
	void SetMessage(string new_message) {
		message = new_message;
		streak = 0;
	}
	void AddStreak() {									//streak incriment.
		streak++;
	}							
	void Print()const {
		//Prints a message if the guess is correct and makes it even more cheer with streak.
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		if (streak == 0) {
			cout << message << endl;
		}
		else if(streak == 1) {
			SetConsoleTextAttribute(h, 4);
			cout << "               Good!" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		else if (streak == 2) {
			SetConsoleTextAttribute(h, 11);
			cout << "               Great!" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		else if (streak == 3) {
			SetConsoleTextAttribute(h, 12);
			cout << "              Awesome!" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		else if (streak == 4) {
			SetConsoleTextAttribute(h, 13);
			cout << "             Outstanding!" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		else {
			SetConsoleTextAttribute(h, 14);
			cout << "              AMAZING!" << endl;
			SetConsoleTextAttribute(h, 15);
		}
	}
	void Clear() {
		message = "";
		streak = 0;
	}
};

