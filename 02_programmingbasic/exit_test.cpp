// return_statement.cpp
#include <stdlib.h>
struct S 
{
    int value;
};
int main()
{
    S s{ 3 };
    exit( 3 );
    // or
    return 3;
}