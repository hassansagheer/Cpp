#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<cstdio>
using namespace std;

//structure declaration
struct Book { int ID; char category[20]; char name[20]; char author[20]; int quantity; float price; int rack; char student[20]; }Info;

//function declaration
void book_info(); void add_book(); void del_book(); void search_book(); void issue_book(); void book_list(); void book_record(); void main_menu();
//function declaration of issue book;
//iss=issue;     //bk=book;
void iss_bk(); void view_iss_bk(); void search_iss_bk(); void remove_iss_bk();

//function declaration of file handling;
void library();
////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	char ch; cout << endl << endl << endl << endl << endl; cout << endl << "\t\t\t\t       UNIVERSITY INSITUTE OF INFORMATION & TECHNOLOGY"; cout << endl << "\t\t\t\t  ======================================================="; cout << endl << "\n\t\t\t\t\tPROJECT NAME:"; cout << endl << "\n\t\t\t\t\t\t\t\t\" LIBRARY MANAGEMENT \""; cout << endl << "\n\n\t\t\t\t\tPRESENTED TO:"; cout << endl << "\n\t\t\t\t\t\t\t\t\" DR. KASHIF SATTAR \""; cout << endl << "\n\t\t\t\t\tGROUP MEMBERS:\n"; cout << endl << "\t\t\t\t\tHASSAN SAGHEER          19-ARID-1000"; cout << endl << "\t\t\t\t\tNABEEL KHIZER           19-ARID-1044"; cout << endl << "\t\t\t\t\tNAILA BAITOOL           19-ARID-1045"; cout << endl << "\t\t\t\t\tSADIA HASSAN            19-ARID-1061\n"; cout << endl << "\t\t\t\t  ======================================================="; cout << endl << "\n\n\t\t\t\t\tPress Enter for Main Menu...."; _getche(); main_menu(); return 0;
}//main function end;

void main_menu()
{
	system("cls"); char ch; cout << endl << endl << endl << endl << endl; cout << "\t\t\t\t\t-------------MAIN MENU-------------"; cout << endl << "\n\t\t\t\t\t1. " << "Add Books"; cout << endl << "\t\t\t\t\t2. " << "Delete Books"; cout << endl << "\t\t\t\t\t3. " << "Search Books"; cout << endl << "\t\t\t\t\t4. " << "Issue Books"; cout << endl << "\t\t\t\t\t5. " << "View Book List"; cout << endl << "\t\t\t\t\t6. " << "Edit Book Record"; cout << endl << "\t\t\t\t\t7. " << "Close Application" << endl; cout << endl << "\n\t\t\t\t\tEnter Your Choice = "; cin >> ch; if (ch == '1') { add_book(); }
	else if (ch == '2') { del_book(); }
	else if (ch == '3') { search_book(); }
	else if (ch == '4') { issue_book(); }
	else if (ch == '5') { book_list(); }
	else if (ch == '6') { book_record(); }
	else if (ch == '7') { exit(0); }
	else { main_menu(); }
}//main function end;
void book_info()		//define function;
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << endl << "\t\t\t\t\t----------------ENTER BOOK DETAIL-----------------";
	cin.ignore();
	cout << endl << "\n\t\t\t\t\tBook ID = ";   cin >> Info.ID;   cin.ignore();
	cout << "\t\t\t\t\tBook Category = ";   cin.getline(Info.category, 20);
	cout << "\t\t\t\t\tBook Name = "; 	cin.getline(Info.name, 20);             //////////?????????????
	cout << "\t\t\t\t\tAuthor Name = ";	cin.getline(Info.author, 20);
	cout << "\t\t\t\t\tBooks Quantity = ";	cin >> Info.quantity;
	cout << "\t\t\t\t\tPrice of Book in RS. = ";	cin >> Info.price;
	cout << "\t\t\t\t\tRack no. = ";	cin >> Info.rack;
	cout << endl << endl;
}
void add_book()			//define function;
{
	system("cls");
	int ch;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-------------SELECT CATEGORY OF BOOK TO ADD TO LIBRARY-------------";
	cout << endl << "\n\t\t\t\t\t1. " << "English";
	cout << endl << "\t\t\t\t\t2. " << "Computer";
	cout << endl << "\t\t\t\t\t3. " << "Mathematics";
	cout << endl << "\t\t\t\t\t4. " << "Urdu";
	cout << endl << "\t\t\t\t\t5. " << "Islamic Study";
	cout << endl << "\t\t\t\t\t6. " << "Science";
	cout << endl << "\t\t\t\t\t7. " << "History" << endl;
	cout << endl << "\n\t\t\t\t\tEnter Your Choice = "; cin >> ch;

	if (ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5 || ch == 6 || ch == 7)
	{
		library();
	}
	else
	{
		system("cls");
		cout << endl << endl << endl << endl << endl;
		cout << "\t" << "\t\t\t\t\tWrong entry!" << endl;
		cout << endl << "\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();

	}
}
void del_book()			//define function;
{
	system("cls");
	int count = 0;
	int ID;
	char ch, ch1;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-------------DELETE BOOK FROM LIBRARY-------------";
	cout << endl << "\n\t\t\t\t\tEnter ID = ";
	cin >> ID;

	ifstream file4;
	file4.open("lib.txt");
	{
		file4 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file4.eof())
	{
		if (ID == Info.ID)
		{
			count++;
			cout << "\n\n\n\t\t\t\t\t==>Record found:\n" << endl;
			cout << "\n\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tBook Category = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Author = " << Info.author << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack no. = " << Info.rack << endl;
			cout << "\n\n" << "\t\t\t\t\tPress \"Y\" to delete Book: \n\t\t\t\t\t";
			cout << "\n\n" << "\t\t\t\t\tPress \"N\" if you don't want to delete Book:\n\t\t\t\t\t";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				ifstream file1;
				file1.open("lib.txt");
				ofstream file2;
				file2.open("newlib.txt", ios::app);
				{
					file1 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				while (!file1.eof())
				{
					if (ID != Info.ID)
					{
						file2 << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << endl;
					}
					file1 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				file1.close();
				file2.close();
			}
			else if (ch == 'n' || ch == 'N')
			{
				main_menu();
			}
		}
		file4 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file4.close();
	if (count == 1)
	{
		remove("lib.txt");
		if (rename("newlib.txt", "lib.txt") == 0)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << endl << "\t\t\t\t\tBook deleted successfully\n";
			cout << endl << "\t\t\t\t\tPress \"Y\" to delete more: \n\n" << "\t\t\t\t\tPress \"M\" for Main Menu: \n\t\t\t\t\t";
			cin >> ch1;
			if (ch1 == 'y' || ch1 == 'Y')
			{
				del_book();
			}
			if (ch1 == 'm' || ch1 == 'M')
			{
				main_menu();
			}
		}
		else if (rename("newlib.txt", "lib.txt") != 0)
		{
			remove("newlib.txt");
			cout << "\n\t\t\t\t\tBook not deleted successfully!\n\n";
			cout << "\t\t\t\t\tPress Any Key to try again...";
			_getch();
			exit(1);
		}
	}
	else if (count == 0)
	{
		cout << endl << endl;
		cout << "\n\t\t\t\t\tRecord not Found\n";
		cout << "\n\t\t\t\t\tPress Enter for Main Menu....";
		_getche();
		main_menu();
	}
}

void issue_book()			//define function
{
	system("cls");
	char ch;
	cout << endl << endl << endl << endl << endl;
	cout << endl << "\t\t\t\t\t-------------ISSUE BOOK FROM LIBRARY-------------";
	cout << endl << "\n\t\t\t\t\t1. " << "Issue Book";
	cout << endl << "\t\t\t\t\t2. " << "View Issued Book";
	cout << endl << "\t\t\t\t\t3. " << "Search Issued Book";
	cout << endl << "\t\t\t\t\t4. " << "Remove Issued Book" << endl;
	cout << endl << "\n\t\t\t\t\tEnter Your Choice = ";
	cin >> ch;

	if (ch == '1')
	{
		iss_bk();
	}
	else if (ch == '2')
	{
		view_iss_bk();
	}
	else if (ch == '3')
	{
		search_iss_bk();
	}
	else if (ch == '4')
	{
		remove_iss_bk();
	}
	else
	{
		system("cls");
		cout << endl << endl << endl << endl << endl;
		cout << endl << "\t\t\t\t\t\tWrong Entry!" << endl;
		cout << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getch();
		main_menu();
	}
}
void book_list()		//define function
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << endl << "\t\t\t\t--------------------BOOK LIST--------------------\t\t" << endl;
	cout << endl;
	cout << setw(15) << "CATEGORY" << "\t" << setw(15) << "BOOK NAME" << "\t" << setw(15) << "BOOK ID" << "\t" << setw(15) << "AUTHOR NAME" << "\t" << setw(15) << "QUANTITY" << "\t" << setw(15) << "BOOK PRICE" << "\t" << setw(15) << "RACK NO." << "\t" << endl;
	cout << "========================================================================================================================\n";
	ifstream file7;
	file7.open("lib.txt");
	{
		file7 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file7.eof())
	{
		cout << endl << setw(15) << Info.category << "\t" << setw(15) << Info.name << "\t" << setw(15) << Info.ID << "\t" << setw(15) << Info.author << "\t" << setw(15) << Info.quantity << "\t" << setw(15) << Info.price << "\t" << setw(15) << Info.rack << "\t" << endl;
		file7 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file7.close();

	cout << "\n\n\n\t\t\t\t\tPress Enter for Main Menu...";
	_getch();
	main_menu();

}
void book_record()		//define function
{
	system("cls");
	int count3 = 0;
	int ID;
	char ch, ch1;
	cout << endl << endl << endl << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t-------------MODIFY RECORD-------------";
	cout << endl << "\n\t\t\t\t\tEnter ID = ";
	cin >> ID;

	ifstream file15;
	file15.open("lib.txt");
	{
		file15 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file15.eof())
	{
		if (ID == Info.ID)
		{
			count3++;
			cout << "\n\n\t\t\t\t\tRecord found:\n" << endl;
			cout << "\n\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tBook Category = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Author = " << Info.author << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack no. = " << Info.rack << endl;
			cout << "\n\n" << "\t\t\t\t\tPress \"Y\" to Update Book Record: ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				ifstream file16;
				file16.open("lib.txt");
				ofstream file17;
				file17.open("newlib.txt", ios::app);
				{
					file16 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				while (!file16.eof())
				{
					if (ID != Info.ID)
					{
						file17 << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << endl;
					}
					file16 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				book_info();
				{
					file17 << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << endl;
				}
				file16.close();
				file17.close();
			}
			else
			{
				main_menu();
			}
		}
		file15 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file15.close();
	if (count3 == 1)
	{
		remove("lib.txt");
		if (rename("newlib.txt", "lib.txt") == 0)
		{
			cout << "\n\n\t\t\t\t\tRecord Updated Successfully\n";
			cout << endl << "\t\t\t\t\tPress \"Y\" to update more: " << "\t\t\t" << "Press \"M\" for Main Menu: \n\t\t\t\t\t\t\t\t\t";
			cin >> ch1;
			if (ch1 == 'y' || ch1 == 'Y')
			{
				book_record();
			}
			if (ch1 == 'm' || ch1 == 'M')
			{
				main_menu();
			}
		}
		else if (rename("newlib.txt", "lib.txt") != 0)
		{
			remove("newlib.txt");
			cout << "\n\t\t\t\t\tRecord not Updated successfully!\n\n";
			cout << "\t\t\t\t\tPress Any Key to try again...";
			_getch();
			exit(1);
		}
	}
	else if (count3 == 0)
	{
		cout << endl << endl << endl << endl << endl;
		cout << endl << "\t\t\t\t\tRecord not Found: " << endl;
		cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();
	}
}
//define functions of Issue Book section
void iss_bk()
{
	system("cls");
	int count4 = 0;
	int ID;
	cout << endl << endl << endl << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t-------------ISSUE BOOK SECTION-------------";
	cout << endl << "\n\t\t\t\t\tEnter student name  = ";
	cin >> Info.student;
	cout << endl << "\t\t\t\t\tEnter \"Book ID\" you want to issue = ";
	cin >> ID;

	ifstream file8;
	file8.open("lib.txt");
	ofstream file9;
	file9.open("issue_book.txt", ios::app);
	{
		file8 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file8.eof())
	{
		if (ID == Info.ID)
		{
			count4++;
			cout << endl << "\t\t\t\t\tBook Issued Successfully" << endl;
			file9 << Info.student << "\t" << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << "\t" << endl;
			cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
			_getche();
			main_menu();
		}
		file8 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	if (count4 == 0)
	{
		cout << endl << "\t\t\t\t\tRecord not Found" << endl;
		cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();
	}
	file8.close();
	file9.close();
}
void view_iss_bk()
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << endl;
	cout << "\t\t\t\t-------------ISSUED BOOK LIST-------------\n" << endl;
	cout << "  STUDENT" << "    " << "BOOK ID" << "\t  " << "CATEGORY" << "\t   " << "BOOK NAME" << "\t   " << "AUTHOR" << "\t   " << "QUANTITY" << "\t" << "BOOK PRICE" << "\t" << "RACK" << endl;
	cout << "========================================================================================================================" << endl;
	ifstream file10;
	file10.open("issue_book.txt");
	{
		file10 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file10.eof())
	{
		cout << Info.student << "\t" << setw(10) << Info.ID << "\t" << setw(10) << Info.category << "\t" << setw(10) << Info.name << "\t" << setw(10) << Info.author << "\t" << setw(8) << Info.quantity << "\t" << setw(10) << Info.price << "\t" << setw(4) << Info.rack << "\t" << endl;
		file10 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file10.close();

	cout << endl << "\n\n\t\t\t\t\tPress Enter for Main Menu...";
	_getche();
	main_menu();
}
void search_iss_bk()
{
	system("cls");
	int count5 = 0;
	int ID;
	cout << endl << endl << endl << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t-------------SEARCH ISSUED BOOK-------------";
	cout << endl << "\n\t\t\t\t\tEnter ID = ";
	cin >> ID;

	ifstream file11;
	file11.open("issue_book.txt");
	{
		file11 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file11.eof())
	{
		if (ID == Info.ID)
		{
			count5++;
			cout << endl << "\t\t\t\t\tRecord Found" << endl;
			cout << endl << "\t\t\t\t\tStudent Name = " << Info.student << endl << "\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tCategory = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack = " << Info.rack << endl;
			cout << endl << "\n\n\t\t\t\t\tPress Enter for Main Menu...";
			_getche();
			main_menu();
		}
		file11 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file11.close();
	if (count5 == 0)
	{
		cout << endl << "\t\t\t\t\tRecord not Found" << endl;
		cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();
	}
}
void remove_iss_bk()
{
	system("cls");
	int count6 = 0;
	int ID;
	char ch, ch1;
	cout << endl << endl << endl << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t-------------REMOVE ISSUED BOOK-------------";
	cout << endl << "\n\t\t\t\t\tEnter ID to remove = ";
	cin >> ID;

	ifstream file12;
	file12.open("issue_book.txt");
	{
		file12 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	while (!file12.eof())
	{
		if (ID == Info.ID)
		{
			count6++;
			cout << "\n\n\t\t\t\t\tRecord found:\n" << endl;
			cout << endl << "\t\t\t\t\tStudent Name = " << Info.student << endl << "\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tCategory = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack = " << Info.rack << endl;
			cout << "\n\n" << "\t\t\t\t\tPress \"Y\" to remove Issued Book: ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				ifstream file13;
				file13.open("issue_book.txt");
				ofstream file14;
				file14.open("newissue_book.txt", ios::app);
				{
					file13 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				while (!file13.eof())
				{
					if (ID != Info.ID)
					{
						file14 << Info.student << "\t" << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << endl;
					}
					file13 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
				}
				file13.close();
				file14.close();
			}
			else
			{
				remove_iss_bk();
			}
		}
		file12 >> Info.student >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
	}
	file12.close();
	if (count6 == 1)
	{
		remove("issue_book.txt");
		if (rename("newissue_book.txt", "issue_book.txt") == 0)
		{
			cout << "\n\t\t\t\t\tBook removed successfully\n";
			cout << endl << "\t\t\t\t\tPress \"Y\" to delete more: " << "\t\t\t\t\t" << "Press \"M\" for Main Menu: " << endl;
			cin >> ch1;
			if (ch1 == 'y' || ch1 == 'Y')
			{
				remove_iss_bk();
			}
			if (ch1 == 'm' || ch1 == 'M')
			{
				main_menu();
			}
		}
		else if (rename("newissue_book.txt", "issue_book.txt") != 0)
		{
			remove("newissue_book.txt");
			cout << "\n\t\t\t\t\tBook not removed successfully!\n\n";
			cout << "\t\t\t\t\tPress Any Key to try again...";
			_getch();
			exit(1);
		}
	}
	else if (count6 == 0)
	{
		cout << endl << endl << endl << endl << endl;
		cout << endl << "\t\t\t\t\tRecord not Found: " << endl;
		cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void library()
{
	char ch;
	book_info();
	ofstream file("lib.txt", ios::app);
	{
		file << Info.ID << "\t" << Info.category << "\t" << Info.name << "\t" << Info.author << "\t" << Info.quantity << "\t" << Info.price << "\t" << Info.rack << endl;
		cout << endl << endl << "\t\t\t\t\tPress \"Y\" to add another book" << endl;
		cout << "\n\n" << "\t\t\t\t\tPress \"M\" for Main Menu\n\t\t\t\t\t";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			add_book();
		}
		else if (ch == 'M' || ch == 'm')
		{
			main_menu();
		}
	}file.close();
}


void search_book()			//define function;
{
	int x = 0;
	int y = 0;
	int id;
	int n;
	char nam[20];
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << endl << "\t\t\t\t\t-------------SEARCH BOOK IN LIBRARY-------------";
	cout << endl << "\n\t\t\t\t\t1. " << "By ID";
	cout << endl << "\t\t\t\t\t2. " << "By Name" << endl;
	cout << endl << "\n\n\t\t\t\t\tEnter Your Choice = ";  cin >> n;
	system("cls");

	if (n == 1)
	{
		cout << endl << endl << endl << endl << endl;
		cout << endl << "\t\t\t\t\t-------------ENTER BOOK ID TO SEARCH-------------";
		cout << endl << "\n\t\t\t\t\tEnter ID = ";
		cin >> id;

		ifstream file5;
		file5.open("lib.txt");
		{
			file5 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
		}
		while (!file5.eof())
		{
			if (id == Info.ID)
			{
				x++;
				cout << "\n\n" << "\t\t\t\t\tRecord Found: \n" << endl;
				cout << "\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tBook Category = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Author = " << Info.author << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack no. = " << Info.rack << endl;
				cout << endl << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
				_getche();
				main_menu();

			}
			file5 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
		}
		if (x == 0)
		{
			cout << endl << endl << endl << endl << endl;
			cout << endl << "\t\t\t\t\tRecord not Found: " << endl;
			cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
			_getche();
			main_menu();
		}
		file5.close();
	}
	else if (n == 2)
	{
		cout << endl << endl << endl << endl << endl;
		cout << endl << "\t\t\t\t\t-------------ENTER BOOK NAME TO SEARCH-------------";
		cout << endl << "\n\t\t\t\t\tEnter Name = ";
		cin >> nam;

		ifstream file6;
		file6.open("lib.txt");
		{
			file6 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
		}
		while (!file6.eof())
		{
			if (_strcmpi(nam, Info.name) == 0)
			{
				y++;
				cout << "\n\n" << "\t\t\t\t\tRecord Found: \n" << endl;
				cout << "\n\t\t\t\t\tBook ID = " << Info.ID << endl << "\t\t\t\t\tBook Category = " << Info.category << endl << "\t\t\t\t\tBook Name = " << Info.name << endl << "\t\t\t\t\tBook Author = " << Info.author << endl << "\t\t\t\t\tBook Quantity = " << Info.quantity << endl << "\t\t\t\t\tBook Price = " << Info.price << endl << "\t\t\t\t\tRack no. = " << Info.rack << endl;
				cout << endl << endl << "\n\n\t\t\t\t\tPress Enter for Main Menu...";
				_getche();
				main_menu();
			}
			file6 >> Info.ID >> Info.category >> Info.name >> Info.author >> Info.quantity >> Info.price >> Info.rack;
		}
		if (y == 0)
		{
			cout << endl << endl << endl << endl << endl;
			cout << endl << "\t\t\t\t\tRecord not Found: " << endl;
			cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
			_getche();
			main_menu();
		}
		file6.close();
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tWrong Entry!" << endl;
		cout << endl << "\n\t\t\t\t\tPress Enter for Main Menu...";
		_getche();
		main_menu();
	}
}
