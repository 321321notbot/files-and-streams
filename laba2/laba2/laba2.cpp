#include "stdafx.h"
#include "fileParser.h"
#include "text.h"
using namespace std;

int main()
{

	string name = "text1.txt";
	text a(name);
	a.fileParse();
	a.showText();	
	return 0;
}

