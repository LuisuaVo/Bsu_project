#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int sled(int** mas, int n);
void get_matr(int** mas, int n);

int main()
{
	int n;
	cout << "Enter razmer matrix: ";
	cin >> n;
	srand(time(NULL));
	int** mas;
	mas = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			mas[i][j] = rand() % 21;
	}
	cout << "Matrix" << endl;
	get_matr(mas, n);
	cout << "Summa: " << sled(mas, n);
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

void get_matr(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(2) << mas[i][j] << " ";
		cout << endl;
	}
}

int sled(int** mas, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mas[i][i];
	}
	return sum;
}