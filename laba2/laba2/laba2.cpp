#include "stdafx.h"
#include "text.h"
using namespace std;

void printMenu();

int main()
{
	setlocale(LC_ALL, "rus");
	string name1 = "text1.txt";
	string name2 = "text2.txt";
	string name3 = "text3.txt";
	printMenu();
	while (true)
	{
		switch (getchar())
		{
		case '1':
		{
			text a(name1);
			a.fileParse();
			a.showText();		
			break;
		}
		case '2':
		{
			text b(name2);
			b.fileParse();
			b.showText();
			break;
		}
		case '3':
		{
			text c(name3);
			c.fileParse();
			c.showText();
			break;
		}
		case '4':

			cout << "Exit" << endl;
			exit(EXIT_SUCCESS);
		}

	}

	return 0;
}

void printMenu() {
	cout << "Выберите вариант работы программы:\n" << "1.Все предложения записаны в одну строку" << endl << "2.Каждое предложение записано в отдельной строке" << endl
		<< "3. Предложения на разных строках, конец предложения может быть перенесен на другую строку" << endl << "4. Выход" << endl;
}