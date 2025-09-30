//SequenceContainers
#include<iostream>
#include<array>

#define tab "\t"
using namespace std;
using std::cout;
using std::cin;
using std::endl;

try
{
	unsigned long long int factorial(int n)
	{
		if (n == 0) return 1;
		return n * factorial(n - 1);
	}
}
catch (const std::exception&)
{

}

//#define STL_ARRAY
#define STL_EXCEPTION_HW

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

#ifdef STL_EXCEPTION_HW

		int n;
		cout << "Enter factorial of number: "; cin >> n;
		cout << "Rezult: " << factorial(n) << endl;
	

#endif // STL_EXCEPTION_HW



}