#include <iostream>
#include <cmath>;
using namespace std;

long long transform(int n);

int main()
{
	long long n;
	cout << "Enter n: ";
	cin >> n;
	n = transform(n);
	cout << "Chislo: " << n;
}

long long transform(int n)
{
	long long k = n;
	int N = 0;
	while (n != 0)
	{
		N = N + 1;
		n /= 10;
	}
	n = k;
	if (N % 2 != 0)
	{
		int N2 = N / 2;
		int ch = n / pow(10, N2);
		int cif = ch % 10;
		n = cif * pow(10, N + 1) + k * 10 + cif;
	}
	return n;
}

