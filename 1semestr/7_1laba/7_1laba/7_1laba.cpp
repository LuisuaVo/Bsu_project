#include <iostream>
using namespace std;

class kompl
{
private:
	double d;
	double k;
public:
	kompl() { d = 0; k = 0; }
	kompl(double dei, double kom) { d = dei; k = kom; }
	void get_inf()
	{
		cout << "Vvedite chislo a+bi: ";
		char i, zn;
		cin >> d >> zn >> k >> i;
		if (zn == '-')
			k = -k;
	}
	void put_inf()
	{
		cout << " result: ";
		char i, zn;
		if (k > 0 && d != 0)
			cout << d << "+" << k << "i" << endl;
		if (k < 0 && d != 0)
			cout << d << k << "i" << endl;
		if (k == 0)
			cout << d << endl;
		if (d == 0 && k != 0)
			cout << k << "i" << endl;
	}
	kompl summ(kompl k2)
	{
		kompl kom;
		kom.d = d + k2.d;
		kom.k = k + k2.k;
		return kom;
	}
	kompl min(kompl k2)
	{
		kompl kom;
		kom.d = d - k2.d;
		kom.k = k - k2.k;
		return kom;
	}
	kompl pr(kompl k2)
	{
		kompl kom;
		kom.d = d * k2.d - k * k2.k;
		kom.k = k * k2.d + d * k2.k;
		return kom;
	}

	kompl del(kompl k2)
	{

		kompl kom;
		if (k2.d * k2.d + k2.k * k2.k == 0)
			throw "delenie na nol";
		kom.d = (d * k2.d + k2.k * k) / (k2.d * k2.d + k2.k * k2.k);
		kom.k = (k * k2.d - k2.k * d) / (k2.d * k2.d + k2.k * k2.k);
		return kom;

	}

};
int main()
{
	kompl k1, k2;
	k1.get_inf();
	k2.get_inf();
	cout << "Enter oper: ";
	char zn;
	cin >> zn;
	switch (zn)
	{
	case '+':
	{
		kompl k3 = k1.summ(k2);
		cout << "summa "; k3.put_inf();
		break;
	}
	case '-':
	{
		kompl k4 = k1.min(k2);
		cout << "raznost ";  k4.put_inf();
		break;
	}
	case '*':
	{
		kompl k5 = k1.pr(k2);
		cout << "proizvedenie "; k5.put_inf();
		break;
	}
	case '/':
	{
		try
		{
			kompl k6 = k1.del(k2);
			cout << "delenie "; k6.put_inf();
		}
		catch (...) { cout << "delenie na nol"; }
		break;
	}
	default:
		cout << "oper ne opozn";
		break;
	}


}