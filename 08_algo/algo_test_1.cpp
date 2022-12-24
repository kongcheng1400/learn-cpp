#include <list>
#include <algorithm>
#include <iostream>

bool twice(int e1, int e2) {
    return e1 * 2 == e2;
}

using namespace std;
int main() {
    list<int> L{50, 40, 10, 20, 20};
    list<int>::iterator iter;
    list<int>::iterator result1, result2;

    cout << "L = ( ";
    for (iter = L.begin(); iter != L.end(); iter++) cout << *iter << " ";
    cout << ")" << endl;

    result1 = adjacent_find(L.begin(), L.end());
    if (result1 == L.end())
        cout << "no two adjacent elements that are equal." << endl;
    else
        cout << "adjacent elements : " << *result1 << endl;
    
    result2 = adjacent_find(L.begin(), L.end(), twice);
    if (result2 == L.end())
        cout << "no adjacent of twice." << endl;
    else
        cout << "adjacent of twice: " << *result2++ << endl;
        cout << "&" << *result2 << endl;
}