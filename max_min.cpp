#include<iostream>
using namespace std;

int main(){
int x,y;
cout<<"Enter first number: "; cin>>x;
cout<<"Enter second number: "; cin>>y;
cout<<"\nMaximum number is: "<<max(x,y);
cout<<"\nMinimum number is: "<<min(x,y);
return 0;
}