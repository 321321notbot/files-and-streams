#include "stdafx.h"
#include "fileParser.h"
using namespace std;

void fileParser(string name)
{
	ifstream file;
	string chosenSentence;
	string otherSentence;
	file.open(name);
	if (file.is_open())
		cout << "file is readable" << endl;
	else
	{
		cout << "File doesnt exist" << endl;
	}

	while (!file.eof())
	{
		string sentence;
		string buffer;
		getline(file, sentence);
		if (findDot(sentence))
		{
			if (sentence[1] == ' ') 
				chosenSentence += sentence; 
			else
				otherSentence += sentence;
				
		}
		else {
			buffer = sentence;
			getline(file, sentence);
			buffer += sentence;
			if (findDot(buffer))
			{
				if (buffer[1] == ' ')
					chosenSentence += buffer;
				else
					otherSentence += buffer;

			}
			
		}
		
		
	}
	cout << chosenSentence << endl << otherSentence;
	file.close();
}