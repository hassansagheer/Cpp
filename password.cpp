#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

int main()
{
	string pass="";
	char ch;
	cout<<"\nEnter Password = ";
	ch=getch();
	while(ch!='\r')
	{
		pass.push_back(ch);
		cout<<'*';
		ch=getch();
	}
	if(pass=="hello")
	{
		cout<<"\nYes";
	}
	else 
	{
		cout<<"\nPlease try again...";
		_getch();
		system("cls");
		main();
	}
	
	return 0;
}
