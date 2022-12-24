// using_exit_or_return1.cpp
#include <stdio.h>
#include <fstream>
#include <iostream>
class ShowData {
public:
   // Constructor opens a file.
   ShowData( const char *szDev ) {
      //auto err = fopen_s(&OutputDev, szDev, "w" );
      output_dev.open(szDev, std::ios::out);

   }

   // Destructor closes the file.
   ~ShowData() { output_dev.close(); }

   // Disp function shows a string on the output device.
   void Disp(std::string szData) {
      output_dev << szData << std::endl;
   }
private:
   std::ofstream output_dev;
};

//  Define a static object of type ShowData. The output device
//   selected is "CON" -- the standard output device.
ShowData sd1 = "CON";

//  Define another static object of type ShowData. The output
//   is directed to a file called "HELLO.DAT"
ShowData sd2 = "hello.dat";

int main() {
   sd1.Disp( "hello to default device\n" );
   sd2.Disp( "hello to file hello.dat\n" );
}