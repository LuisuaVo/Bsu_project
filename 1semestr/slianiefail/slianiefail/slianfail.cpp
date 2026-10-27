#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
	ifstream in1, in2;
	in1.open("in1.txt", ios::in);
	if (!in1.is_open())
	{
		cout << "Fail 1 isn't open";
		return 1;
	}
	in2.open("in2.txt", ios::in);
	if (!in2.is_open())
	{
		cout << "Fail 2 isn't open";
		return 1;
	}
	ofstream out("out.txt", ios::out);
	if (!out.is_open())
	{
		cout << "Fail out isn't open";
		return 1;
	}
	int num1 = 0, num2 =0;
	if (!(in1>>num1))
		num1 = INT_MAX;
	if (!(in2>>num2))
		num2 = INT_MAX;

	while ((num1 != INT_MAX) || (num2 != INT_MAX))
	{
		if (num1 <= num2)
		{
			out << num1<<" ";
			if (!(in1 >> num1))
				num1 = INT_MAX;
		}

		else
		{
			out << num2 << " ";
			if (!(in2 >> num2))
				num2 = INT_MAX;
		}
	}
	in1.close();
	in2.close();
	out.close();
		
}