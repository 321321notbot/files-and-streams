#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream file;
	string word, word1, word2;
	file.open("text1.txt");
	if (file.is_open())
		cout << "file is readable" << endl;
	else
	{
		cout << "File doesnt exist" << endl;
		return -1;
	}
	while (!file.eof())
	{
		getline(file, word);
		if (word[1] == ' ')
			word1 += word;
		else word2 += word;
	}
	cout << word1 << endl << word2 << endl;
	file.close();
	return 0;
}

