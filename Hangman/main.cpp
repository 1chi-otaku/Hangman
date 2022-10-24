#include <iostream>
#include <Windows.h>
#include "Hangman.h"
using namespace std;




int main() {
	srand(time(NULL));

	Hangman obj;

	int input = 1;
	while (input != 0)
	{
		system("cls");
		obj.Play();
		cout << "Play Again?" << endl;
		cout << "0 - NO" << endl;
		cin >> input;
	}
	

	return 0;
}