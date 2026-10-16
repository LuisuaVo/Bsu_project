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
		string s, el, el1, el2;
		double ch = 0, che = 0;
		int cou = 0;
		while ((a = str.find_first_not_of(str_not, a)) != str.npos)
		{
			b = str.find_first_of(str_not, a);
			s = str.substr(a, b - a);
			if (!s.empty())
			{ //проверка что первый элемент цифра чтобы idx не выдал ошибку из-за отсутствия элемента
				if ((s[0] == '+')|| (s[0] == '-')||(s[0] == '0') || (s[0] == '1') || (s[0] == '2') || (s[0] == '3') || (s[0] == '4') || (s[0] == '5') || (s[0] == '6') || (s[0] == '7') || (s[0] == '8') || (s[0] == '9'))
				{
					size_t idx = 0;
					if ((s.length() == 1) && (s[0] != '-') && (s[0] != '+')) // проверка: если длина строки равна единице и символ не - или + константа правильная
						cout << s << endl;
					if ((s.length() >= 2) && ((s[1] == '.') || (s[1] == '0') || (s[1] == '1') || (s[1] == '2') || (s[1] == '3') || (s[1] == '4') || (s[1] == '5') || (s[1] == '6') || (s[1] == '7') || (s[1] == '8') || (s[1] == '9') || (s[1] == 'e') || (s[1] == 'E') || (s[1] == 'l') || (s[1] == 'L') || (s[1] == 'u') || (s[1] == 'U') || (s[1] == 'F') || (s[1] == 'f'))) //если длина строки больше двух, то вторым символом должна быть цифра или символ типа
					{
						if ((s.length() == 2) && (s[1] != '.'))
							cout << s << endl;
						else if (s.length() > 2)
						{
							ch = stod(s, &idx);
							if (idx == s.length())
							{
								cout << s << endl;
								cou++;
							}
							else
							{  // здесь была проверка idx != 0 но без верхней проверки символа она не сработала
								if ((s.length() == idx + 1) && (s[idx] != 'e') && (s[idx] != 'E') && ((s[idx] == 'l') || (s[idx] == 'L') || (s[idx] == 'u') || (s[idx] == 'U') || (s[idx] == 'F') || (s[idx] == 'f')))// проверка на константу разного типа
								{
									cout << s << endl;
									cou++;
								}
								if (((s[idx] == 'e') || (s[idx] == 'E')) && (idx != s.length())) //проверка на экспоненту
								{
									el1 = s.substr(idx, s.length() - idx); // выделяю символы после экспоненты чтобы прверить чтоб там было число
									if (!el1.empty())
									{
										if ((el1[0] == '-') || (el1[0] == '0') || (el1[0] == '1') || (el1[0] == '2') || (el1[0] == '3') || (el1[0] == '4') || (el1[0] == '5') || (el1[0] == '6') || (el1[0] == '7') || (el1[0] == '8') || (el1[0] == '9') || (el1[0] == '+'))
										{
											if ((el1.length() == 1) && (el1[0] != '-') && (el1[0] != '+'))
												cout << s << endl;
											if ((el1.length() >= 2) && ((el1[0] == '0') || (el1[1] == '1') || (el1[1] == '2') || (el1[1] == '3') || (el1[1] == '4') || (el1[1] == '5') || (el1[1] == '6') || (el1[1] == '7') || (el1[1] == '8') || (el1[1] == '9')))
											{
												size_t ide = 0;
												che = stod(el1, &ide);
												if (ide == el1.length())
												{
													cout << s << endl;
													cou++;
												}
											}
										}
									}

								}
							}
						}
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