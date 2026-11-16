#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

bool ifprost(int ch);
int main()
{
	ifstream in;
	in.open("in.txt", ios::in);
	if (!in)
	{
		cout << "fail in can't be opened";
		return 1;
	}
	int n = 0;
	ofstream out;
	out.open("out.txt", ios::out);
	if (!out)
	{
		cout << "fail out can't be opened";
		return 1;
	}
	string str;
	cout << "Enter prep sign: ";
	string prep;
	getline(cin, prep);
	int k = 0;
	while (getline(in, str))
	{
		if (str != "\n")
		{
			str = str + prep;
			int a = 0, b = 0;
			while ((a = str.find_first_not_of(prep,a)) != string::npos)
			{
				b = str.find_first_of(prep,a);
				string ch = str.substr(a, b - a);
				try
				{
					int chis = stoi(ch);
					n++;
					if (ifprost(abs(chis)))
						k++;
				}
				catch(...){}
				a = b;
			}
		}
	}
	if (n == 0)
	{
		cout << "file has no symb";
	}
	else if (k == 0)
		cout << "file has no prost symb";
	else
	{
		int* matr = new int[k];
		int m = 0;
		in.clear();
		in.seekg(0, ios::beg);
		while (getline(in, str))
		{
			if (str != "\n")
			{
				n++;
				str = str + prep;
				int a = 0, b = 0;
				while ((a = str.find_first_not_of(prep, a)) != string::npos)
				{
					b = str.find_first_of(prep,a);
					string ch = str.substr(a, b - a);
					try
					{
						int chis = stoi(ch);
						if (ifprost(abs(chis)))
							matr[m++] = chis;
					}
					catch (...) {}
					a = b;
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				if (abs(matr[i]) > abs(matr[j]))
				{
					int temp = matr[i];
					matr[i] = matr[j];
					matr[j] = temp;
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			out << matr[i] << " ";
		}
		delete[] matr;
	}
	in.close();
	out.close();
}

bool ifprost(int ch)
{
	int pr = 1, i = 2;
	if (ch != 1 && ch != 0)
	{
		while (i <= sqrt(ch) && (pr))
		{
			if (ch % i == 0 && ch != 0)
				pr = 0;
			i++;
		}
		return (pr == 1 ? true : false);
	}
	else return false;
}