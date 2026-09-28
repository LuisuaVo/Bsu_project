#include <iostream>
#include <ctime>
using namespace std;

int minEl(int* arr, int n);
int sum_do_nul(int* arr, int n);
void krat(int* arr, int n);
void get_mass(int* arr, int n);
void enter_mass_klav(int* arr, int n);
void enter_mass_rand(int* arr, int n);

int main()
{
	const int MAX = 100;
	int arr[MAX];
	int n;
	cout << "Enter razmer massiva: ";
	cin >> n;
	if (n > MAX || n<1)
		cout << "Something went wrong!";
	else
	{
		int yes;
		cout << "How you want to zapolnit massive? (klaviatyra - 0; random - 1): ";
		cin >> yes;
		if (!yes)
		{
			enter_mass_klav(arr, n);
		}
		else
		{
			enter_mass_rand(arr, n);
		}
		cout << "Massive: ";
		get_mass(arr, n);
		cout << endl;

		int min = minEl(arr, n);
		if (min!=0)
			cout << "Minimum dvyxznachny element: " << min << endl;
		else
			cout << "Net dvyxznach elementov"<< endl;

		int s = sum_do_nul(arr, n);

		if (s!=0)
			cout << "Summa elementov do nula: " << s << endl;
		else 
			cout << "Summ doesn't exist!"<< endl;

		if (n < 3)
			get_mass(arr, n);
		else
		{
			krat(arr, n);
			get_mass(arr, n);
		}
	}
	return 0;
}

int minEl(int* arr, int n)
{
	int min = 99;
	int flag = 0;
	int el;
	int kolcif;
	for (int i = 0; i < n; i++)
	{
		kolcif = 0;
		el = arr[i];
		while (el != 0)
		{
			kolcif += 1;
			el /= 10;
		}
		if ((kolcif == 2) && (arr[i] <= min))
		{
			flag = 1;
			min = arr[i];
		}
	}
	return (flag ? min : 0);
}

int sum_do_nul(int* arr, int n)
{
	int nom = n-1;
	int flag = 1;
	int estnol = 0;
	int i = n - 1;
	while (i > 0 && (flag))
	{
		if (arr[i] == 0)
		{
			flag = 0;
			estnol = 1;
		}

		else
		{
			--i;
		}
	}

	int sum = 0;
	if (i > 0)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += arr[j];
		}
	}
	return (estnol? sum:0);
}

void krat(int* arr, int n)
{
	int num = 0;
	int kolkrat = 0;
	for (int k = 0; k < n; k++)
	{
		if (k % 3 == 0)
		{
			int x; long i, j;
			for (int i = k; i > kolkrat ; i--)
			{
				x = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = x;
			}
			++kolkrat;
		}
	}
}

void get_mass(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void enter_mass_klav(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
	}
}

void enter_mass_rand(int* arr, int n)
{
	int a, b, c;
	cout << "Enter interval: ";
	cin >> a >> b;
	c = b - a + 1;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % c + a;
	}
}