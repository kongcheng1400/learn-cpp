#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctorClass {
public:
    explicit FunctorClass(int& evenCount) : m_evenCount(evenCount) {}
    void operator()(int n) const {
        cout << n;
        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++m_evenCount;
        } else {
            cout << " is odd " << endl;
        }
    }
private:
    FunctorClass& operator=(const FunctorClass&);
    int& m_evenCount;
};

int main() {
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

    int evenCount = 0;
    for_each(v.begin(), v.end(), [&evenCount](int n) {
        cout << n;
        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++evenCount;
        } else {
            cout << " is odd " << endl;
        }
    });

    cout << "in lambda: evenCount = " << evenCount << endl;

    //function object implementation:
    evenCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(evenCount));
    cout << "in FunctionObject, evenCount = " << evenCount << endl;
}