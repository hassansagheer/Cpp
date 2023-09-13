// Class-specific new and delete operators
#include <iostream>
#include <cstring>
#include <stddef.h>
using namespace std;
const int MAXNAMES = 5;
class Name
{
public:
Name( const char *s ) { strncpy( name, s, 25 ); }
void display() const { cout << '\n' << name; }
void * operator new ( size_t size );
void operator delete( void * ptr );
~Name() {}; // do-nothing destructor
private:
char name[25];
};
//-------- Simple memory pool to handle fixed number of Names
char pool[MAXNAMES] [sizeof( Name )];
int inuse[MAXNAMES];
// -------- Overloaded new operator for the Name class
void * Name :: operator new( size_t size )
{
for( int p = 0; p < MAXNAMES; p++ )
if( !inuse[p] )
{
inuse[p] = 1;
return pool + p;
}
return 0;
}
// --------- Overloaded delete operator for the Names class
void Name :: operator delete( void *ptr )
{
inuse[((char *)ptr - pool[0]) / sizeof( Name )] = 0;
}
int main()
{
Name * directory[MAXNAMES];
char name[25];
for( int i = 0; i < MAXNAMES; i++ )
{
cout << "Enter name # " << i+1 << ": ";
cin >> name;
directory[i] = new Name( name );
}
for( int i = 0; i < MAXNAMES; i++ )
{
directory[i]->display();
delete directory[i];
}
}
