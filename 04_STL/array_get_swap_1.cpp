#include <array>
#include <iostream>

using namespace std;

typedef array<int, 4> MyArray;

int main()
{
    MyArray c0 { 0, 1, 2, 3 };

    // display contents " 0 1 2 3"
    cout << "MyArray c0 = ";
    for (const auto& e : c0)
    {
        cout << " " << e;
    }
    cout << endl;

    // display odd elements " 1 3"
    cout << " " << get<1>(c0);
    cout << " " << get<3>(c0) << endl;

    MyArray c1 {4, 5, 6, 7};
    cout << "MyArray c1 = ";
    for (const auto & e : c1) { cout << " " << e;}
    cout << endl;

    c0.swap(c1);
    cout << "first swap: c0 = ";
    for (const auto & e : c0) { cout << " " << e;}
    cout << endl;

    swap(c0, c1);
    cout << "2nd swap: c0 = ";
    for (const auto & e : c0) { cout << " " << e;}
    cout << endl;
}