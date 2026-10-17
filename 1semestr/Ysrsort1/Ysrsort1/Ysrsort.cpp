#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std::chrono;

unsigned long long compare1 = 0;
unsigned long long change1 = 0;
unsigned long long compare2 = 0;
unsigned long long change2 = 0;

void sort_chet_nechet(int* arr, int n);
void sort_comb(int* arr, int n);
void get_mass (int* arr, int n);
void reverse_mass(int* arr, int n);
int main()
{
	int n;
	std::cout << "Enter the number of elements in the array: ";
	std::cin >> n;
	if ( n < 1)
		std::cout << "Something went wrong!";
	else 
	{
		int* arr = new int[n];
		if (n == 10)
		{
			std::cout << "Enter elements: ";
			for (int i = 0; i < n; i++)
			{
				std::cin >> arr[i];
			}
			std::cout << "\n";
		}
		else
		{
			int a, b, c;
			std::cout << "Enter interval: ";
			std::cin >> a >> b;
			c = b - a + 1;
			srand(time(NULL));
			for (int i = 0; i < n; i++)
			{
				arr[i] = rand() % c + a;
			}
			int wh;
			std::cout << "What massive do you want: 1 - ascending(v), 2 - descending(u), 3 - random? ";
			std::cin >> wh;
			switch (wh)
			{
			case 1:
				sort_comb(arr, n); 
				break;
			case 2: 
				sort_comb(arr, n); 
				reverse_mass(arr, n);
				break;
			}
				
		}
		//std::cout << "Massive: ";
		//get_mass(arr, n);
		//std::cout << "\n\n";

		int* arr1 = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr1[i] = arr[i];
		}

		compare1 = 0;
		change1 = 0;
		auto start = system_clock::now();
		sort_chet_nechet(arr, n);
		auto end = system_clock::now();
		auto elapsed_seconds = duration_cast<seconds>(end - start).count();
		auto elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
		std::time_t end_time = system_clock::to_time_t(end);
		//std::cout << "Sort chet-nechet massive: ";
		//get_mass(arr, n);
		//std::cout << std::endl << std::endl;
		std::cout << "Sort chet-nechet:\n";
		std::cout << "Calculations are finished on " << std::ctime(&end_time)
			<< "Algorithm execution time: " << elapsed_seconds << "s\n"
			<< "Algorithm execution time: " << elapsed_milliseconds << "ms\n"
			<< "Number of comparisons: " << compare1 << "\n"
			<< "Number of changes: " << change1 << "\n\n\n";

		compare2 = 0;
		change2 = 0;
		start = system_clock::now();
		sort_comb(arr1, n);
		end = system_clock::now();
		elapsed_seconds = duration_cast<seconds>(end - start).count();
		elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
		//std::cout << "Sort comb massive: ";
		//get_mass(arr1, n);
		//std::cout << "\n\n";
		end_time = system_clock::to_time_t(end);
		std::cout << "Sort comb:\n";
		std::cout << "Calculations are finished on " << std::ctime(&end_time)
			<< "Algorithm execution time: " << elapsed_seconds << "s\n"
			<< "Algorithm execution time: " << elapsed_milliseconds << "ms\n"
			<< "Number of comparisons: " << compare2 << "\n"
			<< "Number of changes: " << change2 << "\n";
		delete[] arr;
		delete[] arr1;
	}
}

void get_mass(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void sort_chet_nechet(int* arr, int n)
{
	int ifchange;
	int el;
	do 
	{
		ifchange = 0;
		for (int i = 0; i < n - 1; i+=2)
		{
			++compare1;
			if (arr[i] > arr[i + 1])
			{
				el = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = el;
				ifchange = 1;
				++change1;
			}
		}
		for (int i = 1; i < n - 1; i += 2)
		{
			++compare1;
			if (arr[i] > arr[i + 1])
			{
				el = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = el;
				ifchange = 1;
				++change1;
			}
		}
	} while (ifchange);
}

void sort_comb(int* arr, int n)
{
	int k = n/1.247330950103979;
	int i = 0;
	int ifchange = 1;
	while((k!=0) || (ifchange))
	{
		ifchange = 0;
		for (i = 0; i + k < n; i++)
		{
			++compare2;
			if (arr[i] > arr[i + k])
			{
				int temp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = temp;
				ifchange = 1;
				++change2;
			}
		}
		k /= 1.247330950103979;
		if ((!k) && (ifchange))
			k = 1;
	}
}

void reverse_mass(int* arr, int n)
{
	int temp;
	for (int i = 0; i < n/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i  - 1] = temp;
	}
}
