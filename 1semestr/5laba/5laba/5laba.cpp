#include <iostream>
#include <string>
using namespace std;

int main()
{
	string stri, str, word, bucv1, bucv2;
	cout << "Please, enter string: ";
	getline(cin, stri);
	if (!stri.empty())
	{
		str = stri + " ";
		string iskl = " ", ex = "e", ex2 = "E", point = ".";
		int a = 0, b = 0, leng = 0, isneg = 0;
		long chis = 0, sum = 0;
		size_t pos, exp, exp2, poi;
		while ((a = str.find_first_not_of(iskl, a)) != str.npos)
		{

			b = str.find_first_of(iskl, a);
			word = str.substr(a, b - a);
			leng = word.length();
			pos = 0;
			if (!word.empty())
			{
				bucv1 = word.substr(0, 1);
				if ((bucv1 == "1") || (bucv1 == "2") || (bucv1 == "3") || (bucv1 == "4") || (bucv1 == "5") || (bucv1 == "6") || (bucv1 == "7") || (bucv1 == "8") || (bucv1 == "9") || (bucv1 == "0") || (bucv1 == "-"))
				{
					if ((leng == 1) && (bucv1 != "-"))
						chis = stol(word, &pos);
					if (leng > 1)
					{
						bucv2 = word.substr(1, 1);
						if ((bucv2 == "1") || (bucv2 == "2") || (bucv2 == "3") || (bucv2 == "4") || (bucv2 == "5") || (bucv2 == "6") || (bucv2 == "7") || (bucv2 == "8") || (bucv2 == "9") || (bucv2 == "0"))
						{
							chis = stol(word, &pos);
						}
					}
					if (pos == word.length())
					{
						exp = 0;
						exp2 = 0;
						poi = 0;
						if ((chis < 0) && (word.find(ex, exp) == word.npos) && (word.find(ex2, exp2) == word.npos) && (word.find(point, poi) == word.npos))
						{
							sum += chis;
							++isneg;
						}
					}
				}
			}
			a = b;
		}
		if (isneg)
		{
			stri = to_string(sum) + " " + stri;
			cout << stri;
		}
		else cout << "There are no negative numbers consisted of digit in the row!";
	}
	else cout << "You haven't entered anything";
}