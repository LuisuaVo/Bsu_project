#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <climits>
using namespace std;

bool type_chis(int);

int main()
{
	ifstream IN;
	IN.open("IN.txt", ios::in);
	if (!IN)
	{
		cout << "Cannot open file in! ";
		return 1;
	}
	ofstream OUT;
	OUT.open("OUT.txt", ios::out);
	if (!OUT)
	{
		cout << "Cannot open file out!";
		return 1;
	}
	string rasd, str;
	getline(IN, rasd);
	if (rasd.empty())
	{
		OUT << "You entered no rasdel";
		return 1;
	}
	int ko = 0;
	while (getline(IN, str))
	{
		int a = 0, b = 0;
		int chis = 0;
		string ch;
		int n = 0, min = INT_MAX, pmin = 0, lmax = 0, max = INT_MIN, lmin = 0, pmax = 0;
		string  smax = "", smin = "";
		while ((a = str.find_first_not_of(rasd, a)) != str.npos)
		{
			ko++;
			b = str.find_first_of(rasd, a);
			ch = str.substr(a, b - a);
			try
			{
				chis = stoi(ch);
				if (type_chis(chis))
				{
					n++;
					if (chis > max) { max = chis; pmax = a; lmax = ch.length(); smax = ch; }
					if (chis < min) { min = chis; pmin = a; lmin = ch.length(); smin = ch; }
				}
			}
			catch(...){}
			if (b == str.npos)
				break;
			a = b;
		}
		if (n < 2 && ko != 0 && str != "")
		{
			str = "*" + str;
			OUT << str << endl;
		}
		else if (ko != 0 && str != "")
		{
			string ch1;
			ch1 = max;
			if (pmax > pmin)
			{
				str.replace(pmax, lmax, smin);
				str.replace(pmin, lmin, smax);
			}
			if (pmin > pmax)
			{
				str.replace(pmin, lmin, smax);
				str.replace(pmax, lmax, smin);
			}
			OUT << str << endl;
		}
	}
	if (ko == 0)
		OUT << "You have entered no numbers";
	IN.close();
	OUT.close();
	return 0;
}
bool type_chis(int num)
{
	int est = 1;
	int i = 2;
	while ((est) && (i <= sqrt(num)))
	{
		if (num % i == 0)
			est = 0;
		i++;
	}
	if (num <= 1)
		return false;
	return (est == 1 ? true : false);
}