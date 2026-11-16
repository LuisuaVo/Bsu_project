#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void sortchet(double* matr, int m);
void sortnechet(double* matr, int m);

int main()
{
	ifstream in;
	in.open("in.txt", ios::in);
	if (!in)
	{
		cout << "file in can't be opened";
		return 1;
	}
	ofstream off;
	off.open("out.txt", ios::out);
	double k, l;
	in >> k >> l;
	if (k <= 0 || l <= 0 || int(k) != k || int(l) != l)
	{
		cout << "never vved razm";
		return 1; 
	}
	int n = k, m = l;
	double** matr;
	matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	string str;
	getline(in, str);
	int ifelem=0;
	int i = 0, j = 0;
	while (getline(in, str))
	{
		str = str + " ";
		j = 0;
		ifelem = 1;
		int a = 0, b = 0;
		while ((a = str.find_first_not_of(" ", a)) != str.npos)
		{
			b = str.find_first_of(" ", a);
			string cf = str.substr(a, b - a);
			try
			{
				double ch = stod(cf);
				if (i < n && j < m)
					matr[i][j] = ch;
				j++;
			}
			catch (...)
			{
				cout << "there is ne chislo";
				return 1;
			}
			a = b;
		}
		i++;
	}
	if (j != m || i != n)
	{
		cout << "neprav razm matr";
		return 1;
	}
	for (int h = 0; h < n; h++)
	{
		if (h % 2 == 0)
			sortchet(matr[h], m);
		else
			sortnechet(matr[h], m);
	}
	for (int r = 0; r < n; r++)
	{
		for (int t = 0; t < m; t++)
			off << setw(3) << matr[r][t];
		off << endl;
	}

	for (int b = 0; b < n; b++)
	{
		delete[] matr[b];
	}
	delete[] matr;
	in.close();
	off.close();
}

void sortchet(double* matr, int m)
{
	for(int i =0; i<m; i++)
		for (int j = i + 1; j < m; j++)
			if (matr[i] > matr[j])
			{
				double temp = matr[i];
				matr[i] = matr[j];
				matr[j] = temp;
			}
}

void sortnechet(double* matr, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (matr[j] > matr[i])
			{
				double temp = matr[i];
				matr[i] = matr[j];
				matr[j] = temp;
			}
}