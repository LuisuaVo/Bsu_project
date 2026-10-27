#include <iostream>
#include <cassert>
using namespace std;

long long transform(long long n);

int main()
{
	cout << "Unit-test in MS Visual Studio.";
	return 0;
}

long long transform(long long n)
{
	if (n <= 0)
		return -1;
	else
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
			long long ch = n;
			while (N2 != 0)
			{
				ch = ch / 10;
				N2 -= 1;
			}
			int cif = ch % 10;
			long long pch = cif;
			int K = N + 1;
			while (K != 0)
			{
				pch = pch * 10;
				K -= 1;
			}
			n = pch + k * 10 + cif;
		}
		return n;
	}
}