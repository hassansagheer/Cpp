#include<iostream>
using namespace std;

class MyClass{
public:
int myNum;
string myString;
};

int main(){
MyClass myObj;
cout<<"Enter myNum: ";
cin>>myObj.myNum;
cout<<"Enter myString: ";
cin>>myObj.myString;
cout<<myObj.myNum<<endl;
cout<<myObj.myString;
return 0;
}