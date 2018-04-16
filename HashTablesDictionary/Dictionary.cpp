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