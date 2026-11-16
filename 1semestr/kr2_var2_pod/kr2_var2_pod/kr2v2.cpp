#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int numstrmin(double** matr, int n, int m);
int main()
{
	ifstream in;
	in.open("in.txt", ios::in);
	if (!in)
	{
		cout << "file can't be open";
		return 1;
	}
	string str;
	if (!getline(in, str))
	{
		cout << "file is empty";
		return 1;
	}
	int ifpust = 0;
	in.clear();
	in.seekg(0, ios::beg);
	double l, k;
	in >> l >> k;
	if (l <= 0 || k <= 0 || int(l)!=l || int(k)!=k)
	{
		cout << "Rong razm matr";
		return 1;
	}
	int n = l, m = k;
	double** matr;
	matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	int i = -1, j = -1;
	getline(in, str);
	while (getline(in, str))
	{
		ifpust = 1;
		i++;
		j = -1;
		int a = 0, b = 0;
		str = str + " ";
		while ((a = str.find_first_not_of(" ", a)) != str.npos && j<m-1 && i<n)
		{
			b = str.find_first_of(" ", a);
			string cf = str.substr(a, b - a);
			try
			{
				int ch = stod(cf);
				j++;
				matr[i][j] = ch;
			}
			catch (...)
			{
				cout << "You entered not a number";
				return 1;
			}
			a = b;
		}
	}
	if (ifpust == 0)
	{
		cout << "You have no el";
		return 1;
	}
	int nu= numstrmin(matr, n, m);
	in.clear();
	in.close();
	ofstream out("in.txt", ios::app);
	if (!out)
	{
		cout << "file can't be redact";
		return 1;
	}
	out << "\n****************************\n";
	if (nu == -1)
		cout << "String has no pol el;";
	else out << "String " << nu;
	out.close();
	for (int z = 0; z < n; z++)
	{
		delete[] matr[z];
	}
	delete[] matr;
}

int numstrmin(double** matr, int n, int m)
{
	double min = (numeric_limits<double>::max)();
	int num=-1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matr[i][j] > 0 && matr[i][j] <= min)
			{
				min = matr[i][j];
				num = i+1;
			}
	return num;
}