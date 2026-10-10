#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void enter_mass_klav(int** arr, int n);
void enter_mass_rand(int** arr, int n);
void get_mass(int** mas, int n);
int maxelvp(int** arr, int n);
void sortvozr(int* arr, int n);
void sortub(int* arr, int n);

int main()
{
	int n;
	cout << "Enter razmer matrix: ";
	cin >> n;
	if (n < 1)
		cout << "Something went wrong";
	else
	{
		int** mas;
		mas = new int* [n];
		for (int i = 0; i < n; i++)
		{
			mas[i] = new int[n];
		}
		int yes;
		cout << "How you want to zapolnit massive? (klaviatyra - 0; random - 1): ";
		cin >> yes;
		if (!yes)
		{
			enter_mass_klav(mas, n);
		}
		else
		{
			enter_mass_rand(mas, n);
		}
		cout << "Matrix: " << endl;
		get_mass(mas, n);
		cout << endl;
		cout << "Maxim element: " << maxelvp(mas, n) << endl;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				sortvozr(mas[i], n);
			else
				sortub(mas[i], n);
		}
		cout << "Matrix: " << endl;
		get_mass(mas, n);
		for (int i = 0; i < n; i++)
		{
			delete[] mas[i];
		}
		delete[] mas;
	}
}

void enter_mass_klav(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter (" << i << "," << j << ") element: ";
			cin >> arr[i][j];
		}
	}
}

void enter_mass_rand(int** arr, int n)
{
	int a, b, c;
	cout << "Enter interval: ";
	cin >> a >> b;
	c = b - a + 1;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = rand() % c + a;
	}
}

void get_mass(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << arr[i][j] << " ";
		cout << endl;
	}
}

int maxelvp(int** arr, int n)
{
	int maxel = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (maxel < arr[i][j])
				maxel = arr[i][j];
	}
	return maxel;
}

void sortvozr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}
}

void sortub(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}
}