#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	int m = 0;
	int k = n;
	while (n != 0)
	{
		m = m * 10 + n % 10;
		n = n / 10;
	}
	if (k == m)
		cout << "The number is polindrome";
	else cout << "The number is not a palindrome";
	return 0;
}