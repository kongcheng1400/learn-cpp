#include <iostream>

int main() {
    int a = 3;
    const int *pa = &a; //pointer to const 
    int b = 4;
    pa = &b;
    *pa = 5; //wrong. it's pointer to const
    int * const pa1 = &a; //const pointer
    *pa1 = 5;


    return 0;
}