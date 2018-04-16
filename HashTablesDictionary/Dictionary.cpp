#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <iterator>

//Created by Gabriel Jones

Dictionary::Dictionary() {
	totalWords = 0;
}

void Dictionary::readWords() {
	std::ifstream infile("dict.txt");
	std::string line;
	std::hash<std::string> wordHash;
	long wordIntHash;
	while (getline(infile, line)) { //Read the word on the current line (while loops until there are no words to read)
		wordIntHash = wordHash(line) % 1373; //Hash the word we read in and put it in terms of the size of our array.
		wordList[wordIntHash].push_back(line); //Find the linked list at that hash, and add our word to the end of it.
		totalWords++; //up the totatl words by 1
	}
	infile.close();
}

void Dictionary::checkFile() {
	int totalFileWords = 0, correctWords = 0; //total words in the file, how many words are correctly spelled, you can use this to find the total incorrect words
	std::list<std::string> tempList; //to store our list at the current index
	std::list<std::string>::iterator it; //iterator to loop through liinked list
	std::string fileToCheck, line;
	std::cout << "What file would you like to check for spelling mistakes?" << std::endl;
	getline(std::cin, fileToCheck);
	std::ifstream infile(fileToCheck);
	std::hash<std::string> wordHash;
	long wordIntHash;
	while (infile >> line) { //gets anything seperated by a space
		line = strip(line); //strip the word of any additional contents
		wordIntHash = wordHash(line) % 1373; //find its hash value
		tempList = wordList[wordIntHash]; //find the linked list at that index
		for (it = tempList.begin(); it != tempList.end(); it++) { //loop through that linked list to try and find the matching word
			if (*it == line) { //if it found a match at one of the indexes, up the total correct words by 1
				//std::cout << *it << std::endl;
				correctWords += 1; //only ticks up if word was spelled correctly
			}
		}
		totalFileWords += 1; //always ticks up
	}
	//Total incorrect words is calculated just with total words - correct words, since logically the left over words would be spelled incorrectly
	std::cout << "Total words in Dict.txt: " << totalWords << ", Total words in " << fileToCheck << ": " << totalFileWords << ", Total mispelled words: " << totalFileWords - correctWords << std::endl;
	infile.close();
}

std::string Dictionary::strip(std::string stringToStrip) {
	int counter = 0; //index of the string
	int charToCheck = stringToStrip[counter]; //int value of the char at that position
	std::string goodString = "";
	//remove garbage from front of the word, this while will run until it hits a charcter that isn't considered junk
	while (!((charToCheck > 96 && charToCheck < 123) || (charToCheck > 64 && charToCheck < 91) || (charToCheck > 47 && charToCheck < 58))) { //a-z and A-Z and 0-9
		stringToStrip[counter] = ' '; //sets the string's index to be blank
		counter++; //ups the index to be 1 higher
		if (counter > stringToStrip.size()) { //a word is full of junk characters "--", will just return an empty string
			return "";
		}
		charToCheck = stringToStrip[counter];
	}
	//remove garbage from the end of the word
	counter = stringToStrip.size()-1; //start from the back of the word
	charToCheck = stringToStrip[counter];
	while (!((charToCheck > 96 && charToCheck < 123) || (charToCheck > 64 && charToCheck < 91) || (charToCheck > 47 && charToCheck < 58))) { //a-z and A-Z and 0-9
		stringToStrip[counter] = ' ';
		counter--; //lowers the index back one
		if (counter < 0) { //a word is full of junk characters (should never get this far, but added just in case)
			return "";
		}
		charToCheck = stringToStrip[counter];
	}

	for (int i = 0; i < stringToStrip.size(); i++) { //This loop will remove all the whitespace from the ends of the string by just adding letter characters
		charToCheck = stringToStrip[i];
		if (charToCheck != 32) { //if the character isn't a ' '
			goodString += tolower(stringToStrip[i]); //add it to the new string and convert to a lowercase letter (numbers do nothing)
		}
	}

	return goodString;
	
}