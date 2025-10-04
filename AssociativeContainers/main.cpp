#include<iostream>
#include<map>
#include<list>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define DELIMITER "\n================\n"

#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
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
	for(std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << DELIMITER;
	for (std::pair<int, std::string> i : week)
		cout << i.first << tab << i.second << endl;
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
	for (std::map<std::string, std::list<std::string>>::iterator maper = dictionary.begin(); maper != dictionary.end(); ++maper)
	{
		cout << "Слово: " << maper->first << endl<<"Означает: ";
		//for (std::list<std::string>::iterator sec = maper->second.begin(); cout<<" ", sec != maper->second.end(); ++sec)cout << *sec << (sec!=--maper->second.end() ? "," : ".");
		//cout << DELIMITER;
		//for (std::string elem : maper->second) cout << elem << (elem == maper._Getcont() ? "," : "."); cout << DELIMITER;
	}
#endif

}