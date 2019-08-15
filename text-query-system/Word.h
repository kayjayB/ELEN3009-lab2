#ifndef WORD_H
#define WORD_H


#include <string>
#include <cctype>
using namespace std;

// empty classes to represent different exceptions
class WordContainsNoLetters {};
class WordContainsSpace {};

class Word
{
public:
	// DO NOT MODIFY THE PUBLIC INTERFACE OF THIS CLASS
	
	// constructor
	Word(const string& word);		
	// overloads is-equal-to (or equivalence) operator - this is very useful for testing, 
	// as we can compare words directly
	bool operator==(const Word& rhs) const;			
	// returns true if queryable, false otherwise
	// (according to the brief, words less than 3 characters are not queryable)
	bool isQueryable() const;

private:	
	string _word;
	Word lower_case(const string& entered_Word) const;
	Word remove_punctuation(const string& entered_Word) const;
	Word remove_spaces(const string& entered_Word) const;
	bool no_spaces() const;
	bool not_only_punctuation() const;	
};

#endif

