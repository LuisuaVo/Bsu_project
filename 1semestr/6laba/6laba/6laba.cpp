#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int lengpunct(const string& str, const string& prep);

int main() 
{
	ifstream input;
	input.open("input.txt", ios::in);
	if (!input)
	{
		cout << "Fail \"input.txt\" wasn't opened";
		return 1;
	}
	string str;
	if (!getline(input, str))
	{
		cout << "Fail is empty";
		return 1;
	}
	string prep;
	while (true)
	{
		cout << "Enter punctuation marks: ";
		getline(cin, prep);
		if (prep.empty())
			cout << "You didn't enter anything." << endl;
		else break;
	}
	int maxleng = 0, n = 0;
	int l;
	while (getline(input, str))
	{
		l = lengpunct(str, prep);
		if (l>maxleng)
		{
			maxleng = l;
			n = 1;
		}
		else if (l == maxleng && l!=0)
		{
			n++;
		}
	}
	if (n == 0)
		cout << "There are no such marks";
	else 
	{
		if (n <= 10)
			cout << "There are " << n << " such lines:" << endl;
		if (n > 10)
			cout << "There are " << n << " such lines. First 10:" << endl;
		input.clear();
		input.seekg(0);
		int k = 10;
		while (getline(input, str) && k != 0)
		{
			if (lengpunct(str, prep) == maxleng)
			{
				cout << str << "\n";
				k--;
			}
		}
	}
	input.close();
}


int lengpunct(const string& str, const string& prep)
{
	int maxleng = 0, n = 0;
	int a = 0, b, a1 = 0, b1;
	string sl, maxprep, str1;
	str1 = str + " ";
	while ((a = str1.find_first_not_of(" ", a)) != str1.npos)
	{
		a1 = 0;
		b = str1.find_first_of(" ", a);
		sl = str1.substr(a, b - a);
		sl = sl+ " ";
		while (true)
		{
			if ((a1 = sl.find_first_of(prep, a1)) != sl.npos)
			{
				b1 = sl.find_first_not_of(prep, a1);
				if ((b1 - a1) > maxleng)
				{
					maxleng = b1 - a1;
				}
			}
			else break;
			a1 = b1;
		}
		a = b+1;
	}
	return maxleng;
}