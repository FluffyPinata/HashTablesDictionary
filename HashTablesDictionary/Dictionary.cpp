#include "Dictionary.h"
#include <fstream>
#include <iostream>

Dictionary::Dictionary() {

}

void Dictionary::readWords() {
	std::ifstream infile("dict.txt");
	std::string line;
	std::hash<std::string> wordHash;
	long wordIntHash;
	while (getline(infile, line)) {
		wordIntHash = wordHash(line) % 1373; //Hash the word we read in and put it in terms of the size of our array.
		wordList[wordIntHash].push_back(line); //Find the linked list at that hash, and add our word to the end of it.
	}
	infile.close();
}

void Dictionary::checkFile() {
	std::string fileToCheck;
	std::cout << "What file would you like to check for spelling mistakes?" << std::endl;
	getline(std::cin, fileToCheck);
}

std::string Dictionary::strip(std::string stringToStrip) {
	int counter = 0;
	int charToCheck = stringToStrip[counter];
	std::string goodString = "";
	//remove garbage from front of the word
	while (!((charToCheck > 96 && charToCheck < 123) || (charToCheck > 64 && charToCheck < 91))) { //a-z and A-Z
		stringToStrip[counter] = ' ';
		counter++;
		charToCheck = stringToStrip[counter];
	}
	//remove garbage from the end of the word
	counter = stringToStrip.size()-1;
	charToCheck = stringToStrip[counter];
	while (!((charToCheck > 96 && charToCheck < 123) || (charToCheck > 64 && charToCheck < 91))) { //a-z and A-Z
		stringToStrip[counter] = ' ';
		counter--;
		charToCheck = stringToStrip[counter];
	}

	for (int i = 0; i < stringToStrip.size(); i++) { //This loop will remove all the whitespace from the ends of the string by just adding letter characters
		charToCheck = stringToStrip[i];
		if ((charToCheck > 96 && charToCheck < 123) || (charToCheck > 64 && charToCheck < 91)) {
			goodString += stringToStrip[i];
		}
	}

	return goodString;
	
}