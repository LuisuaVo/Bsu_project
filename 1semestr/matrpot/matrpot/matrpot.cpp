#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream in;
	in.open("in.txt", ios::in);
	if (!in)
	{
		cout << "Fail in isn't opened";
		return 1;
	}
	ofstream out;
	out.open("out.txt", ios::out);
	if (!out)
	{
		cout << "Fail out isn't opened";
		return 1;
	}

	int m;
	in >> m;
	int** matr;
	matr = new int* [m];
	for (int i = 0; i < m; i++)
		matr[i] = new int[m];

	for (int i = 0; i<m ; i++)
		for (int j = 0; j < m; j++)
		{
			in >> matr[i][j];
		}

	int pol = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j <= i; j++)
			if (matr[i][j] > 0)
				pol++;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			out<< setw(2) << matr[i][j] << " ";
		out << endl;
	}
	out << "\n";
	out << pol;

	in.close();
	out.close();
}