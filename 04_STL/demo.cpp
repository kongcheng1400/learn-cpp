#include <iostream>
#include <vector>

using namespace std;
int main() {
    //assign
    vector<int> v1, v2, v3;
    v1.assign(10, 11);
    v2.assign({1, 2, 3, 4, 5, 6, 7});
    v3.assign(v1.begin(), v1.end());
    cout << "assign test: v1,v2, v3 3 overload:" << endl;

    cout << "v1 = ";
    for (auto const& v : v1) { cout << v << ",";}
    cout << endl;

    cout << "v2 = ";
    for (auto const& v: v2) { cout << v << ",";}
    cout << endl;

    cout << "v3 = ";
    for (auto const& v: v3) { cout << v << ",";}
    cout << endl;

    //at() test
    cout << "\nat() test:\n";
    cout << "v1.at(0)=" << v1.at(0) << endl;
    v1.at(0) = 0;
    cout << "change v1[0] to 0: v1.at(0)=" << v1.at(0) << endl;

    //back() test
    cout << "\nback(), front() test:\n";
    cout << "v1.back() = " << v1.back() << endl;
    v1.back() = 0;
    cout << "change v1.back() to 0: v1.back() = " << v1.back() << endl;

    //begin(), end() test:
    cout << "\nbegin(), end() iterator test:\n";
    vector<int>::iterator v1_iter;
    vector<int>::const_iterator v1_citer;
    v1_citer = v1.begin();
    v1_citer = v1.cbegin();
    cout << "v1 = ";
    for (; v1_citer != v1.end(); v1_citer++) {cout << *v1_citer << ",";}
    cout << endl;

    cout << "\ncapacity() test:\n";
    cout << "v1.capacity() = " << v1.capacity() << endl;

    cout << "\ntesting difference type:";
    vector<int>::difference_type diff = v1.begin() - v1.end();
    cout << "diff = " << diff << endl;

    cout << "\nemplace() test:\n";
    cout << "v1 = ";
    for (auto const & i : v1) {cout << i << ",";}
    cout << endl;
    vector<int>::const_iterator temp_iter1 = v1.begin();
    temp_iter1 += 3;
    v1.emplace(temp_iter1, 100);
    cout << "after emplace + 3: v1 = ";
    for (auto const & i : v1) {cout << i << ",";}
    cout << endl;
    cout << "after emplace_back(): v1 = ";
    v1.emplace_back(7);
    for (auto const & i : v1) {cout << i << ",";}
    cout << endl;
    

}