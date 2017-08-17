// -------------------------------------------
//					Line
// -------------------------------------------


#include "Line.h"

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	string line_copy=line;
	vector<Word> words_of_line;
	string delimiter = " ";
	
	seperateString(words_of_line, delimiter, line_copy);
}

bool Line::contains(const Word& search_word) const
{

	if (_line.empty())
		return false;
		
		for (int i=0; i<_line.size();i++)
		{
			if (search_word.isQueryable() && _line[i]==search_word)
			{
			return true;
			}
		}
		
	return false;
	}

void Line::seperateString(vector<Word>& words_of_line, const string& delimiter, string& line_copy)
{
	
	int counter=0;
	size_t pos=0;

	if (!line_copy.empty())
	{
		while ((pos = line_copy.find(delimiter)) != string::npos)
		{
			auto individual_word=line_copy.substr(0,pos);

			line_copy.erase(0, pos+delimiter.length());
			words_of_line.push_back(individual_word);

			counter++;
		
		}
	words_of_line.push_back(line_copy);
	_line=words_of_line;
	}
	else 
	_line.clear();
}