#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char city[50];
	ofstream file("city.txt");    //for writing in a file
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter name of city: " << endl;
		cin >> city;
		file << city << endl;	//write to file
	}
	file.close();
	ifstream out("city.txt");  //for reading from a file
	while (!out.eof())
	{
		out >> city;    //read from file
		cout << city << "\t\t";
	}
	out.close();
	return 0;
}
