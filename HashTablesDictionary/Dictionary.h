#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include <string>

class Dictionary {
private:
	std::list<std::string> wordList[1373];
public:
	Dictionary();
	void readWords();
};

#endif
