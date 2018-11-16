#include "stdafx.h"
#include "text.h"


text::text()
{
}


text::text(string & name)
{
	file.open(name);
	if (file.is_open())
		cout << "File is readable" << endl;
	else
	{
		cout << "File doesnt exist" << endl;
	}
}

text::~text()
{
	file.close();
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
		if (sentence[idx] == '.')
			break;
	}
	if (idx != sentence.size() )
	{
		if (findSpace())
		{
			whatToDo(true,idx);
			
		}
		else
		{
			whatToDo(false,idx);
		}
			
	}
	else
	{
		buffer = sentence;
	}


}

void text::whatToDo(bool flag,int idx)
{
	if (flag)
	{
		if (!isEnd(idx))
		{
			string temp = sentence.substr(0, idx + 1);
			chosenSentence += temp;
			chosenSentence += " ";
			sentence = sentence.substr(idx + 2, (sentence.size() - idx));
			findDot();

		}
		else
		{
			chosenSentence += sentence;
			chosenSentence += " ";
		}
	}
	else 
	{
		if (!isEnd(idx))
		{
			string temp = sentence.substr(0, idx + 1);
			otherSentence += temp;
			otherSentence += " ";
			sentence = sentence.substr(idx + 2, (sentence.size() - idx));
			findDot();
		}
		else
		{
			otherSentence += sentence;
			otherSentence += " ";
		}

	}

}


string text::splitSentence(int i,string s)
{
	if (s=="end")
		return sentence.substr(i + 2, (sentence.size() - i));
	else if (s=="begin")
		return sentence.substr(0, i+1);
}

bool text::isEnd(int i)
{
	if ((sentence.size()-1)!=i)
	return false;
	else return true;
}

void text::showText()
{
	cout <<"Sentences thats start with one-letter word:\n"<< chosenSentence << endl <<"Other sentences:\n"<< otherSentence<<"\n\n\n";
}
