#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<list>
#include <time.h>

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
class Crime;
std::stringstream& operator>>(std::stringstream& ifs, Crime& obj);
class Crime
{
	int violation;
	std::string place;
	tm time;
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
	std::string get_time() const
	{
		char stringtime[256]{};
		strcpy(stringtime, asctime(&time));
		stringtime[strlen(stringtime) - 1] = 0;
		return stringtime;
	}
	std::string save_time()const
	{
		char stringtime[64]{};
		strftime(stringtime, 64, "%Y.%m.%d_%H.%M", &time);
		return stringtime;
	}
	void set_time(const std::string& time)
	{
		char timestring[256] = {};
		strcpy(timestring, time.c_str());
		//YYYY.MM.DD HH.MM
		int parts[5] = {};
		int n = 0;
		const char delimiters[] = "._/-:";
		for (char* pch = strtok(timestring, delimiters); pch; pch = strtok(NULL, delimiters))
			parts[n++] = std::atoi(pch);
		this->time = {};
		this->time.tm_year = parts[0] - 1900;
		this->time.tm_mon = parts[1] - 1;
		this->time.tm_mday = parts[2];
		this->time.tm_hour = parts[3];
		this->time.tm_min = parts[4];
	}
	Crime(int violation, const std::string& place, const std::string& time)
	{
		set_time(time);
		set_violation(violation);
		set_place(place);
	}
	explicit Crime(const std::string& str)
	{
		std::stringstream stream(str);
		stream >> *this;
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(24);
	os << std::left;
	return os << obj.get_time() << " ---> " << VIOLATIONS.at(obj.get_violation()) << "  на  " << obj.get_place();
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.save_time() << " " << obj.get_violation() << " " << obj.get_place();
	return ofs;
}
std::stringstream& operator>>(std::stringstream& ifs, Crime& obj)
{
	std::string time;
	ifs >> time;
	int violation;
	ifs >> violation;
	std::string place;
	std::getline(ifs, place);
	obj.set_time(time);
	obj.set_violation(violation);
	obj.set_place(place);
	return ifs;
}


void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
//::map<std::string, std::list<Crime>> load(const std::string& filename);
std::map<std::string, std::list<Crime>> load(const std::string& filename);

//#define INIT_BASE
//#define INIT_BASE_2
#define LOAD_CHECK

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
	std::map<std::string, std::list<Crime>>base = load("base.txt");
	print(base);

	//std::map<std::string, std::list<Crime>> base2 = load("base.txt");
	//print(base2);
#endif
#ifdef INIT_BASE_2

	std::map<std::string, std::list<Crime>> base =
	{
			{"а777аа", {Crime(4, "пр.Ленина", "2025.12.05 11:12"), Crime(5, "ул.Энтузиастов", "2025.11.06 15:00"), Crime(7, "ул.Ленина", "2025.10.22 21:12"), Crime(8, "ул.Энтузиастов", "2025.09.05 11:12")}},
			{"a123nc", {Crime(2, "ул.Пролетарская", "2025.05.05 11:12"), Crime(3, "ул.Труда", "2025.05.05 11:13")}},
			{"a001eg", {Crime(5, "ул.Листа", "2025.10.13 15:12"), Crime(5, "ул.Октябрьская", "2025.09.12 16:12"), Crime(7, "ул.Ватутина", "2025.08.11 17:12"), Crime(8, "ул.Коперника", "2025.07.10 18:12")}}
	};
	print(base);
	save(base, "base.txt");

#endif // INIT_BASE_2
#ifdef LOAD_CHECK
	std::map<std::string, std::list<Crime>> base = load("base.txt");
	print(base);
#endif // LOAD_CHECK
}
//>>--->
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
			cout << *violation;
		cout << DELIMITER;
	}
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		fout << plate->first << ":";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(), cout<<","; ++violation)
		{
			fout << *violation;
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
			// time_crime[SIZE];
			/*std::string time_crime;
			std::getline(fin, time_crime, ',');
			base[licence_plate].push_back(Crime(time_crime));
			cout << time_crime << " ";*/
			char all_crimes[SIZE];
			fin.getline(all_crimes, SIZE);
			cout << all_crimes << endl;
			const char delimiters[] = ",";
			for (char* pch = strtok(all_crimes, delimiters); pch; pch = strtok(NULL, delimiters))
			{
				base[licence_plate].push_back(Crime(pch));
			}
			{
				/*Crime crime(0,"");
				std::stringstream stream(pch);
				stream >> crime;
				base[licence_plate].push_back(crime);*/
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