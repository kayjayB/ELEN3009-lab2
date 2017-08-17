// -------------------------------------------
//					Paragraph
// -------------------------------------------


#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	
	_paragraph.push_back(line); // adding lines to the paragraph
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	line_numbers.clear();
	bool containsWord=false;
	for (int i=0; i< _paragraph.size(); i++)
	{
		if(_paragraph[i].contains(search_word))
		{
			//line_numbers[i]=i;
			line_numbers.push_back(i+1);
			containsWord = true;
		}
	}

return containsWord;

}