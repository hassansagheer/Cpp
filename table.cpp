#include<iostream>
using namespace std;

int main(){
int x;
cout<<"Enter number to print its table: ";
cin>>x;
for(int i=1; i<=10; i++)
{
	cout<<x<<" X "<<i<<" = "<<x*i<<endl;
}
return 0;
}
