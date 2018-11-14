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
	string puncMarks;

public:
	text();
	text(string& name);
	void fileParse();
	void sentenceCheck();
	void findDot();
	bool findSpace();
	char whatMark();
	bool isEnd(int i);
	void whatToDo(bool flag,int idx);
	//void 
	string splitSentence(int i, string s);
	void showText();

	~text();
};

