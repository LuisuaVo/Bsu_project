#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in;
	in.open("in.txt", ios::in);
	if (!in)
	{
		cout << "file in can't be open";
		return 1;
	}
	ofstream off;
	off.open("out.txt", ios::out);
	if (!off)
	{
		cout << "file off can't be open";
		return 1;
	}
	string str;
	int ifelem = 0;
	if (!getline(in, str));
	in.clear();
	in.seekg(0, ios::beg);
	int n = 1;
	while (getline(in, str))
	{
		if (str != "")
		{
			ifelem = 1;
			off << n << ") ";
			n++;
			int a = 0, b = 0;
			while ((a = str.find_first_not_of(" ", a)) != str.npos)
			{
				b = str.find_first_of(" ", a);
				string slov = str.substr(a, b - a);
				for (int i = 0; i < slov.length() / 2; i++)
				{
					char temp = slov[i];
					slov[i] = slov[slov.length() - i - 1];
					slov[slov.length() - i - 1] = temp;
				}
				off << slov << " ";
				a = b;
			}
			off << endl;
		}
	}
	if (ifelem == 0)
		cout << "file has no symb";
	in.close();
	off.close();
}