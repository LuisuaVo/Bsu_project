#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float e, x, sinx, a;
	int n = 1;
	sinx = 0;
	cout << "Enter gr e, x: ";
	cin >> e >> x;
	a = x;
	while (abs(a) > e)
	{
		sinx = sinx + a;
		a = -a * x * x / ((n + 1) * (n + 2));
		n = n + 2;
	}
	cout << "sin(x)=" << sinx;
	cout << "std sin(x)      = " << sin(x) << endl;
	cout << "Difference      = " << abs(sinx - sin(x)) << endl;
	return 0;
}