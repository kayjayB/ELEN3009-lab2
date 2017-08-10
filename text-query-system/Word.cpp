// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word): _word{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (_word.empty()) throw WordContainsNoLetters();

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (_word == rhs._word)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
	return false;
}
