#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str1[]="hello";
	char str2[]="WORLD";
	char str3[]="hello ";
	char str4[5];
	
	cout<<"String Lenth: "<<strlen(str1);		//the null '\0' include but not count
	cout<<endl<<strcat(str1,str2);        // strcat makes two strings in a line or in one paragraph

	strcpy(str4,str1);    // copy str1 and paste str1 in str4
	cout<<endl<<str4;     
	
	cout<<endl<<strcmp(str1,str3);    // strcmp is used to compare two strings 
	
	cout<<endl<<strupr(str1);
	cout<<endl<<strlwr(str2);
	
	return 0;
}
