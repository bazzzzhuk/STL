#include<iostream>
#include<array>
#include<vector>
#include<stdexcept>
#include <fenv.h> 
#include<cmath>

#define tab "\t"
#define DILIMITER "\n===============================\n"
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

	unsigned long long int factorial(int n)
	{
		try
		{
			if (n == 0) return 1;
			/*if (math_errhandling & MATH_ERREXCEPT) {
				if (fetestexcept(FE_OVERFLOW)) throw FE_OVERFLOW;
			}*/
			return n * factorial(n - 1);
		}
		catch (const std::overflow_error& ofe)
		{
			std::cerr << ofe.what() << endl;
		}
		//catch (FE_OVERFLOW)
		//{
		//	//std::cerr << "" << endl;
		//}
		catch (...)
		{
			std::cerr << "Arithmetic overflow?...Maybe try with a smaller number?!" << endl;
		}
	}

	template<typename T>void vector_info(const std::vector<T>& vec);

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_EXCEPTION_HW

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер который хранит данные в виде статического массива;
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			cout << arr.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	/*catch (...)
	{
		std::cout << "Error: Something went wrong" << endl;
	}*/
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	//std::string 
	
#endif // STL_ARRAY
#ifdef STL_VECTOR
	std::vector<int> vec = {0,1,1,2,3,5,8,13,21,34};
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	vector_info(vec);
	cout << endl;
	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	vector_info(vec);
	cout << endl;
	for(std::vector<int>::reverse_iterator it=vec.rbegin();it!=vec.rend(); ++it)
		cout << *it << tab;
	vector_info(vec);
	cout << endl;
	cout << "shrink_to_fit" << endl;
	//vec.shrink_to_fit();
	/*vector_info(vec);
	vec.reserve(1600);
	vec.push_back(1024);*/
	vec.resize(18);
	for (int i : vec)cout << i << tab;
	vector_info(vec);
	cout << "insert" << endl;
	int index;
	int value;
	cout << "Enter index: "; cin >> index;
	cout << "Enter value: "; cin >> value;
	vec.insert(vec.begin() + index, value);
	for (int i : vec)cout << i << tab;

#endif // STL_VECTOR
#ifdef STL_EXCEPTION_HW

		int n;
		cout << "Enter factorial of number: "; cin >> n;
		cout << "Rezult: " << factorial(n) << endl;

#endif // STL_EXCEPTION_HW

}
template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << endl;
	cout << "Size:\t" << vec.size() << endl;//фактический размер Вектора, сколько элементов хранит вектор
	cout << "Max_Size:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;//Объем зарезервированной памяти. 
	// Зарезервированная память нужна для того чтобы ускорить процесс добавления элементов 
	// и избежать необходимости переопределять память при каждом добавленни элемента -
	// Это экономит ресурсы процессорного времени, но расходует дополнительные ресурсы памяти.
	// Если у вектора есть свободная зарезервированная память, то добавляемое значение просто записывается в конец массива,
	// но если зарезервированная память закончилась, то при добавлении элемента вектор резервирует новую память
	// в половину больше фактического размера(в 1.5 раза больше фактического размера)
	// На CAPACITY можно повлиять при помощи методов reserve(), resize(), shrink_to_fit().
	cout << DILIMITER << endl;
}