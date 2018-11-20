#pragma once
#include "stdafx.h"
using namespace std;
class text
{
private:
	ifstream file;
	string sentence;
	string chosenSentence;
	string otherSentence;
	string buffer;

public:
	text(string& name);
	void fileParse();
	void sentenceCheck();
	void findDot();
	bool findSpace();
	bool isEnd(int i);
	void whatToDo(bool flag,int idx);
	string splitSentence(int i, string s);
	void showText();

	~text();
};

