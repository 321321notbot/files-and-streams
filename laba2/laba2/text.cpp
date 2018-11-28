#include "stdafx.h"
#include "text.h"

text::text(string & name)
{
	file.exceptions(ifstream::failbit);
	try 
	{
		file.open(name);
		fileParse();
		showText();
		file.close();
	}
	catch (const ifstream::failure& exc)
	{
		cout << "Error while opening file: " << name << endl
			<< exc.what() << endl<<endl;
	}
}

text::~text()
{ 
}

void text::fileParse()
{
	while (!file.eof())
	{
		getline(file, sentence);
		sentenceCheck();
	}
}


void text::sentenceCheck()
{
	
	if (!buffer.empty())
	{
		string temp = sentence;
		sentence = buffer;
		sentence += temp;
		buffer.erase(buffer.begin(), buffer.end());
	}
	findDot();


}

bool text::findSpace()
{	
	if (sentence[1] == ' ') return true;
	else return false;
}

void text::findDot()
{
	
	int idx;
	for (idx=0;idx<sentence.size();idx++)
	{
		if (sentence[idx] == '.' || sentence[idx] == '!'  || sentence[idx] == '?')
			break;
	}
	if (idx == 1)
	{
		chosenSentence += sentence.substr(0, idx + 1);
		sentence.erase(0, idx+2);
		if (!sentence.empty())
			findDot();
	}
	if (idx != sentence.size() && !sentence.empty())
		whatToDo(findSpace(), idx);
	else
		buffer = sentence;


}

void text::whatToDo(bool hasSpace,int idx)
{
	if (hasSpace)
	{
		if (!isEnd(idx))
		{
			string temp = sentence.substr(0, idx + 1);
			chosenSentence += temp + " ";
			sentence = sentence.substr(idx + 2, (sentence.size() - idx));
			findDot();

		}
		else
		{
			chosenSentence += sentence + " ";
		}
	}
	else 
	{
		if (!isEnd(idx))
		{
			string temp = sentence.substr(0, idx + 1);
			otherSentence += temp + " ";
			sentence = sentence.substr(idx + 2, (sentence.size() - idx));
			findDot();
		}
		else
		{
			otherSentence += sentence + " ";
		}

	}

}

bool text::isEnd(int i)
{
	if ((sentence.size()-1)!=i)
	return false;
	else return true;
}

void text::showText()
{
	if (chosenSentence.empty())
		cout << "No sentences that start with one-letter word :( \n" << "Other sentences:\n" << otherSentence << "\n\n\n";
	else 
		cout <<"Sentences thats start with one-letter word:\n"<< chosenSentence << endl <<"Other sentences:\n"<< otherSentence<<"\n\n\n";
}
