// -------------------------------------------
//					Word
// -------------------------------------------


#include "Word.h"

Word::Word(const string& word): _word{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (_word.empty()) throw WordContainsNoLetters();
	if (no_spaces()) throw WordContainsSpace();
	if (not_only_punctuation()) throw WordContainsNoLetters();
	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	Word LHS_no_punct=remove_punctuation(_word);
	Word RHS_no_punct=remove_punctuation(rhs._word);
	Word LHS_lowercase = lower_case(LHS_no_punct._word);
	Word RHS_lowercase = lower_case(RHS_no_punct._word);
	if (LHS_lowercase._word == RHS_lowercase._word)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
	const int MIN_SIZE_FOR_QUERY=3;
	if (_word.size()>=MIN_SIZE_FOR_QUERY)
		return true;
	else 
	return false;
}

Word Word::lower_case(const string& entered_Word) const
{
	string lowercase_word= entered_Word;
	for (int i=0; i<entered_Word.size();i++)
	{
		lowercase_word[i]=tolower(entered_Word[i]);
	}
	return Word(lowercase_word);
}

Word Word::remove_punctuation(const string& entered_Word) const
{
	string punctuation_to_remove = "~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\"";
	string no_punctuation= entered_Word;
	for (int i=0; i<punctuation_to_remove.size();i++)
	{
		for (int j=0; j<no_punctuation.size();j++)
		{
			if (no_punctuation[j]==punctuation_to_remove[i])
			{
				no_punctuation.erase(j,1);
				j--;
			}
		}
	}
	return no_punctuation;
}

bool Word::no_spaces() const
{
	string space =" ";
	string find_space= _word;
	
	bool exists = find_space.find(space) !=string::npos; // if there are spaces before the end of the string, return true
	
	return exists;
}

bool Word::not_only_punctuation() const
{
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int k=0;
	for (int i=0; i<alphabet.size();i++)
	{
		for (int j=0; j<_word.size();j++)
		{
			if (_word[j]==alphabet[i])
			{
				k=1;
				break;
			}
		}
	}
	if (k==1)
		return false;
	else 
		return true;
}
	