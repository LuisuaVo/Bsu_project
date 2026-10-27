#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "enter const: ";
	getline(cin, str);
	if (!str.empty())
	{
		str = str + " ";
		string str_not = " ,:;";
		int a = 0, b = 0;
		string s;
		double ch = 0;
		int cou = 0;
		while ((a = str.find_first_not_of(str_not, a)) != str.npos)
		{
			b = str.find_first_of(str_not, a);
			s = str.substr(a, b - a);
			if (!s.empty())
			{
				if (((s[0] == '0') || (s[0] == '1') || (s[0] == '2') || (s[0] == '3') || (s[0] == '4') || (s[0] == '5') || (s[0] == '6') || (s[0] == '7') || (s[0] == '8') || (s[0] == '9')) || (((s[0] == '-') || (s[0] == '+') || (s[0] == '.')) && (s.length()>1)))
				{
					size_t idx = 0;
					try
					{
						ch = stod(s, &idx);
						if (idx == s.length())
						{
							cout << s << endl;
							cou++;
						}
						else
						{
							if ((s.length() == idx + 1) && ((s[idx] == 'l') || (s[idx] == 'L') || (s[idx] == 'F') || (s[idx] == 'f')))// проверка на константу разного типа
							{
								cout << s << endl;
								cou++;
							}
							if ((s.length() == idx + 1) && ((s[idx] == 'U') || (s[idx] == 'u'))&& (s.find(".") == s.npos) && (s.find("e") == s.npos) && (s.find("E") == s.npos))
							{
								cout << s << endl;
								cou++;
							}
						}
					}
					catch (const std::exception&)
					{

					}				 
				}
			}
			a = b;
		}
		if (cou == 0)
			cout << "There is no correctly written constants!";
	}
	else cout << "The line is empty; you haven't entered anything.";
}