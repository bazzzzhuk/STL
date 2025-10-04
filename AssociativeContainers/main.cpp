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
		std::pair<int, std::string>(0, "�����������"),
		std::pair<int, std::string>(1, "�����������"),
		std::pair<int, std::string>(2, "�������"),
		std::pair<int, std::string>(3, "�����"),
		{4,"�������"},
		{5,"�������"},
		{6,"�������"},
		{7,"�����������"}
	};
	for(std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << DELIMITER;
	for (std::pair<int, std::string> i : week)
		cout << i.first << tab << i.second << endl;
	cout << DELIMITER;
	cout << "DICTIONARY -> �������";
	std::map<std::string, std::list<std::string>>dictionary =
	{
		{"occasionaly",{"������","����� �� �������","��������","�������"}},
		{"causes",{"�������","��������� �..."}},
		{"space",{"������","������������","������"}},
		{"void",{"�������","������","������"}},
		{"sequence",{"������������������","���","������"}},
		{"consequence",{"���������","�����������","�����"}}
	};
	cout << DELIMITER;
	for (std::map<std::string, std::list<std::string>>::iterator maper = dictionary.begin(); maper != dictionary.end(); ++maper)
	{
		cout << "�����: " << maper->first << endl<<"��������: ";
		//for (std::list<std::string>::iterator sec = maper->second.begin(); cout<<" ", sec != maper->second.end(); ++sec)cout << *sec << (sec!=--maper->second.end() ? "," : ".");
		//cout << DELIMITER;
		//for (std::string elem : maper->second) cout << elem << (elem == maper._Getcont() ? "," : "."); cout << DELIMITER;
	}
#endif

}