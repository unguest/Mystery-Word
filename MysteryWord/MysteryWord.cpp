﻿// MysteryWord.cpp : Entry point for the console application.
//

#include "stdafx.h";
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int play();
int main();
std::string shakeTheWord(std::string word);
std::string defineWord();
void askReplay();

int main()
{
	srand(time(0));
	play();
	return EXIT_SUCCESS;
}

std::string shakeTheWord(std::string wordToShake) {
	
	do{
	std::string wordShaked;
	for (int i = wordToShake.size(); i > 0; --i) {
		int position = rand() % wordToShake.size();
		wordShaked.push_back(wordToShake[position]);
		wordToShake.erase(position, 1);
	}
	}while(wordShaked == wordToShake);
	
	return wordShaked;
}

void askReplay() {
	std::cout << "\n \n Do you want to replay ? y = \"yes\" anything else = \"no\" " << std::endl;
	std::string reply;
	getline(std::cin, reply);
	if (reply == "y"){
		main();
	}
	else {
		std::cout << "Bye Bye ! \n by Unguest :: github.com/unguest" << std::endl;
		getchar();
	}
}

std::string defineWord() {
	std::string wordToSend;
	std::cout << "Make sure the other player don't see you and enter the word :" << std::endl;
	getline(std::cin, wordToSend);
	std::cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"; // we never know :)
	return wordToSend;
}

int play() {
	bool found;
	std::string playerInput;
	std::string wordShaked;
	std::string word = defineWord();
	int counter = 0;
	do {
		
		wordShaked = shakeTheWord(word);
		std::cout << "The word is : " << wordShaked <<  std::endl;
		getline(std::cin, playerInput);
		++counter;

		if (playerInput == word) {

			std::cout << "You found the word that was : " << word << " in " << counter << " times !";
			found = true;
		}
		else {
			std::cout << "Sorry but it is not the correct answer... \n";
			found = false;
		}

	}while (!found);
	askReplay();
	return 0;
}
