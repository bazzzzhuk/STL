#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<list>

using std::cout;
using std::cin;
using std::endl;


#define DELIMITER "\n============================\n"

const std::map<int, std::string> VIOLATIONS =
{
	{0,"N/A"},
	{1, "Парковка в неположенном месте"},
	{2, "Непристёгнутый ремень безопасности"},
	{3, "Пересечение сплошной"},
	{4, "Превышение скорости"},
	{5, "Проезд на красный"},
	{6, "Выезд на встречную полосу"},
	{7, "Езда в нетрезвом состоянии"},
	{8, "Оскорбление инспектора"}
};

class Crime
{
	int violation;
	std::string place;
public:
	int get_violation()const
	{
		return violation;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_violation(int violation)
	{
		this->violation = violation;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	Crime(int violation, const std::string& place)
	{
		set_violation(violation);
		set_place(place);
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(44);
	os << std::left;
	return os << VIOLATIONS.at(obj.get_violation()) << "\t" << obj.get_place();
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_violation() << " " << obj.get_place();
	return ofs;
}
std::stringstream& operator>>(std::stringstream& ifs, Crime& obj)
{
	int violation;
	ifs >> violation;
	std::string place;
	std::getline(ifs, place);
	obj.set_violation(violation);
	obj.set_place(place);
	return ifs;
}


void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
//::map<std::string, std::list<Crime>> load(const std::string& filename);
std::map<std::string, std::list<Crime>> load(const std::string& filename);

//#define INIT_BASE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INIT_BASE
	std::map<std::string, std::list<Crime>>base =
	{
		{"a777aa", {Crime(4, "ул.Ленина"),Crime(5, "ул.Ленина"),Crime(7, "ул.Энтузиастов"),Crime(8, "ул.Энтузиастов")}},
		{"a123bb", {Crime(2, "ул.Пролетарская"),Crime(5, "ул.Ленина")}},
		{"У904ка", {Crime(5, "ул.Октябрьская"),Crime(8, "ул.Ленина"),Crime(7, "ул.Энтузиастов")}}

	};
	print(base);
	save(base, "base.txt");
#endif
	std::map<std::string, std::list<Crime>>base = load("base.txt");
	print(base);

	//std::map<std::string, std::list<Crime>> base2 = load("base.txt");
	//print(base2);
}
//>>--->
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << "\t" << *violation << endl;
		}
		cout << DELIMITER;
	}
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		fout << plate->first << ":";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << *violation << ",";
		}
		fout << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}
std::map<std::string, std::list<Crime>> load(const std::string& filename)
{
	std::map<std::string, std::list<Crime>>base;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			std::getline(fin, licence_plate, ':');
			cout << licence_plate << "\t";
			const int SIZE = 1024 * 500;
			char all_crimes[SIZE];
			//std::string all_crimes;
			fin.getline(all_crimes, SIZE);
			cout << all_crimes << endl;
			const char delimiters[] = ",";
			for (char* pch = strtok(all_crimes, delimiters); pch; pch = strtok(NULL, delimiters))
			{
				Crime crime(0,"");
				std::stringstream stream(pch);
				stream >> crime;
				base[licence_plate].push_back(crime);
			}
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	fin.close();
	return base;
}

//std::map<std::string, std::list<Crime>> load(const std::string& filename)
//{
//	std::ifstream fin(filename);
//	if (fin.is_open())
//	{
//		std::map<std::string, std::list<Crime>> base = {};
//		std::list<Crime> load_list;
//
//		while (!fin.eof())	//EndOfFile
//		{
//			std::string buffer;
//			std::string buffer2;
//			std::string plate;
//			int violation;
//			std::string place;
//
//			std::getline(fin, buffer);
//			if (buffer.size() < 2 || buffer.size() == 0 || buffer[0] == '=')continue;
//			if (buffer.find(':') != std::string::npos)
//			{
//				plate = buffer.substr(0, buffer.find(':'));
//				cout << plate << endl;
//			}
//			else
//			{
//				for (std::pair<int, std::string> it : VIOLATIONS)
//				{
//					if (buffer.substr(1, buffer.find_last_not_of(' ', 44)) == it.second)
//					{
//						violation = it.first;
//						//cout << violation << endl;
//					}
//				}
//				place = buffer.substr(46, std::string::npos);
//				load_list.push_back({ violation, place });
//				//cout << place << endl;
//				base = { {  plate,{load_list}  } };
//				//base.insert({ plate,{load_list} });
//			}
//		}
//		return base;
//	}
//	else
//	{
//		std::cerr << "Error: File not found" << endl;
//	}
//	//?) Закрываем поток:
//	fin.close();
//	
//
//}