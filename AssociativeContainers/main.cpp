#include<iostream>
#include <iomanip>
#include<map>
#include<list>
#include<forward_list>
#include<set>

#include<conio.h>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define DELIMITER "\n==========================\n"

//#define STL_MAP_WEEK
//#define STL_MAP_DICTIONARY
//#define OOO_GIBDD
//#define STL_SET
class GIBDD;

class GIBDD
{
	std::map<std::string, std::list<std::string>>dataBase_penalty = { {"Номер авто", {"Штрафы"}} };
	/*struct Number_auto
	{
		char letter;
		std::string number;
		std::string letters;
		std::string region;
	};*/
public:
	GIBDD() {};

	GIBDD(std::map<std::string, std::string> maper)
	{
		cout << " " << endl;
	}
	~GIBDD()
	{
	}
	void Enter_penalty()
	{
		std::string number;
		std::string penalty;
		cout << "Введите номер авто: \t"; cin >> number;
		cout << "Введите штраф: \t"; cin >> penalty;
		add_gibdd(number, penalty);
	}
	void add_gibdd(std::string number, std::string penalty)
	{
		dataBase_penalty.insert({ number, {penalty} });
		cout << " " << endl;
	}
	void Menu()
	{
		cout << "1. Ввести новый штраф" << endl;
		cout << "2. Проверить штрафы по номеру" << endl;
		cout << "3. Полная распечатка базы данных" << endl;

		char key;
		key = _getch();

		switch (key)
		{
		case '1': Enter_penalty(); break;
		case '2': cout << "two" << endl; break;
		case '3': print(); break;
		default: system("cls"); Menu();
			break;
		}
		Menu();
	};
	void print()const
	{
		cout << DELIMITER << endl;
		//Прямой вывод:
		/*for (std::pair<std::string, std::list<std::string>>maper : dataBase_penalty)
		{
			cout << maper.first<<tab tab tab;
			for (std::string sec : maper.second) cout << sec << "\t"; cout << DELIMITER;
		}*/
		//Вывод по-порядку
		for (std::map<std::string, std::list<std::string>>::const_reverse_iterator maper = dataBase_penalty.crbegin(); maper != dataBase_penalty.crend(); ++maper)
		{
			cout.width(15);
			cout << std::left << maper->first;
			for (std::list<std::string>::const_iterator sec = maper->second.begin(); sec != maper->second.end(); ++sec)cout << *sec << (sec != --maper->second.end() ? "," : ".");
			cout << DELIMITER;
			//for (std::string sec : maper->second) cout << sec << (sec == *maper.end() ? "," : "."); cout << delimiter;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP_WEEK
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Воскресенье"),
		std::pair<int, std::string>(1, "Понедельник"),
		std::pair<int, std::string>(2, "Вторник"),
		std::pair<int, std::string>(3, "Среда"),
		{4,"Четверг"},
		{5,"Пятница"},
		{6,"Суббота"},
		{7,"Воскресенье"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << DELIMITER;
	for (std::pair<int, std::string> i : week)
		cout << i.first << tab << i.second << endl;
#endif
#ifdef STL_MAP_DICTIONARY
	cout << DELIMITER;
	cout << "DICTIONARY -> СЛОВАРЬ";
	std::map<std::string, std::list<std::string>>dictionary =
	{
		{"occasionaly",{"иногда","Время от времени","случайно","изредко"}},
		{"causes",{"причина","приводить к..."}},
		{"space",{"космос","пространство","пробел"}},
		{"void",{"пустота","вакуум","пробел"}},
		{"sequence",{"последовательность","ряд","эпизод"}},
		{"consequence",{"следствие","последствие","вывод"}}
	};
	cout << DELIMITER;
	//for (std::map<std::string, std::list<std::string>>::iterator maper = dictionary.begin(); maper != dictionary.end(); ++maper)
	for(std::pair<std::string, std::list<std::string>> maper:dictionary)
	{
		cout << "Слово: " << maper.first << endl << "\tОзначает: ";
		//for (std::list<std::string>::iterator sec = maper->second.begin(); cout << " ", sec != maper->second.end(); ++sec)cout << *sec << (sec != --maper->second.end() ? "," : ".");
		//cout << DELIMITER;
		for (std::string sec : maper.second) cout << sec << (sec == *--maper.second.end() ? "." : ","); cout << DELIMITER;
	}
#endif // STL_MAP_DICTIONARY
#ifdef OOO_GIBDD
	GIBDD gibdd;
	gibdd.Menu();
#endif // OOO_GIBDD
#ifdef STL_SET
	std::set<int> set = { 1024,512,2048,128,3072,768 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET


}