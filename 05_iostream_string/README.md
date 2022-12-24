## output streams
- ostream, ofstream , ostringstream
- a destination for bytes

### ostream
ostream, basic_ostream, supports cout, cerr, clog.
- ostream: can be configured for buffered or unbuffered, best suited for text
- ofstream: disk file output. binay or byte with open.

### ofstream
open(): reuse the same stream object with a series of files.
close()
put()
wirte(): albock of memory to an output file stream.
! operator重载为fail: if(!cout) 等效于 if(cout.fail()), void* operator重载:if(cout) 等效于 if(!cout.fail())
#### buffering.


construtors:
```C++
ofstream myFile; // Static or on the stack
myFile.open("filename");

ofstream* pmyFile = new ofstream; // On the heap
pmyFile->open("filename");

ofstream myFile("filename", ios_base::out);//append mode ios::app
```
### member functions
3种类型:
1. manipulators
2. unformatted write 
3. modify stream state.
### insertion operators & format
sequential, formatted output:
- format: output, alignment, precision, radix.
-  setw() in iomanip
- cout.width(), ios::cout.fill(),
- alignment: setiosflags, resetiosflags
- precision: setprecision(), 
- std::quoted() in iomanip
- flush; endl; flushes the buffer and outputs a carriage return line feed.

```C++
// setw.cpp
// compile with: /EHsc
#include <iostream>
#include <iomanip>
using namespace std;

int main( )
{
   double values[] = { 1.23, 35.36, 653.7, 4358.24 };
   const char *names[] = { "Zoot", "Jimmy", "Al", "Stan" };
   for( int i = 0; i < 4; i++ )
      cout << setw( 7 )  << names[i]
           << setw( 10 ) << values[i] << endl;
}

```


