// vector_assign.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto& v : v1){
        cout << v << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (auto& v : v2){
        cout << v << " ";
    }
    cout << endl;

    v3.assign(7, 4);
    cout << "v3 = ";
    for (auto const & v : v3){
        cout << v << " ";
    }
    cout << endl;

    v3.assign({ 5, 6, 7 });
    for (auto& v : v3){
        cout << v << " ";
    }
    cout << endl;

    //testing at:
    cout << "testing at v1 = ";
    for (auto const & v : v1) {
        cout << v << " ";
    }
    cout << endl;

    const int& at1 = v1.at(1);
    int& at2 = v1.at(2);
    at2 = 60;
    cout << "after testing at v1 = ";
    for (auto const & v : v1) {
        cout << v << " ";
    }
    cout << endl;
}