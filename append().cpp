#include<iostream>
using namespace std; 

int main(){
string first, second;
cout<<"Enter first name: ";
getline(cin,first);
cout<<"Enter second name: ";
getline(cin,second);
cout<<"appen() function"<<endl;
cout<<first.append(second);
cout<<"length() function"<<endl;
cout<<first.length();
cout<<"size() function"<<endl;
cout<<second.size();
}