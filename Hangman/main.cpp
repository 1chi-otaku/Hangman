#include <iostream>
#include <Windows.h>
#include "Hangman.h"
using namespace std;




int main() {
	srand(time(NULL));

	Hangman obj;

	obj.Play();

	return 0;
}