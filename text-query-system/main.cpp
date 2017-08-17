#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"
#include <string>
#include <iostream>


using namespace std;
int main()
{
string file_name;
string word_to_search;

cout << "Please enter a file name:  " ;
cin >> file_name;

while (true)
{
	cout << endl;

	cout << "Please enter a word to search for or \".\" to quit:  " ;
	cin >> word_to_search;

	if (word_to_search == ".")
		break;

	FileReader read_file(file_name);

	Paragraph search_text;
	read_file.readFileInto(search_text);

	vector<int> line_numbers;
	bool check =search_text.contains(word_to_search, line_numbers);

	if (check)
	{
		cout << "Word found: " << endl;
		for (int i=0; i<line_numbers.size();i++)
		{
			cout << "line " << line_numbers[i] << endl;
		}
	}
	else 
	{
		cout << "Word not found" << endl;
	}
}

	return 0;
}
// The code does not indicate that a word has been found more than once on the same line. It just indicates
// that the word has been found on that line. The Paragraph::contains() function would have to be modified to 
// compensate for this. 


		