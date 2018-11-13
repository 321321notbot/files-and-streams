#include "stdafx.h"
#include "findDot.h"

using namespace std;

bool findDot(string s)
{
	string::iterator it;
	
	for (it = s.begin(); it != s.end(); ++it)
	{
		if (*it == '.')
			return true;
	}
	return false;
}