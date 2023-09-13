#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a, b, x;
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
	x = a - b;
	try
	{
		if (x != 0)
		{
			cout << "Result = " << (a / (a - b));
		}
		else
		{
			throw(x);
		}
	}
	catch (int m)
	{
		cout << "\nDivision by Zero";
	}
	
	_getch();
	return 0;
}