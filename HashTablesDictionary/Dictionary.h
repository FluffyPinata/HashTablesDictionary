#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include <string>

class Dictionary {
private:
	std::list<std::string> wordList[1373];
	int totalWords;
public:
	Dictionary();
	void readWords();
	void checkFile();
	std::string strip(std::string stringToStrip);
};

#endif
