/*
A sample program with the Date class. Use of constructors is shown here.
*/
#include <iostream>
using namespace std;
//#include <stdlib.h>
// defining the Date class
class Date{
// interface of the class
public:
void display(); // to display the date on the screen
void setDay(int i); // setting the day
void setMonth(int i); // setting the month
void setYear(int i); // setting the year
int getDay(); // getting the value of day
int getMonth(); // getting the value of month
int getYear(); // getting the value of year
// Constructors of the class
Date();
Date(int, int, int);
// hidden part of the class
private:
int day, month, year;
};
// defining the constructor
// default constructor. setting the date to a default date
Date::Date()
{
day = 1;
month = 1;
year = 1900;
}
// Constructors with default arguments
Date::Date(int theDay, int theMonth, int theYear = 2002)
{
day = theDay;
month = theMonth;
year = theYear;
}
// The display function of the class date
void Date::display()
{
cout << "The date is " << getDay() << "-" << getMonth() << "-" << getYear()
<< endl;
}
// setting the value of the day
void Date::setDay(int i)
{
day = i;
}
// setting the value of the month
void Date::setMonth(int i)
{
month = i;
}
// setting the value of the year
void Date::setYear(int i)
{
year = i;
}
// getting the value of the day
int Date::getDay()
{
return day;
}
// getting the value of the month
int Date::getMonth()
{
return month;
}
// getting the value of the year
int Date::getYear()
{
return year;
}
// Main program. We will take three date objects using constructors, and display the date.
int main()
{
Date date1, date2(1, 1, 2000), date3(10,12); // taking objects of Date class
// displaying the dates on the screen
date1.display();
date2.display();
date3.display();
}
