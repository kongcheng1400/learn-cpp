#include <iostream>
using namespace std;

class Base {
public:
    virtual void NameOf();
    void InvokingClass();
};

void Base::NameOf() {
    cout << "Base::NameOf\n";
}

void Base::InvokingClass() {
    cout << "Invoked by Base\n";
}

class Derived: public Base {
public:
    void NameOf() override;
    void InvokingClass(); //non virtual function; 
};

void Derived::NameOf() {
    cout << "Derived::NameOf\n";
}

void Derived::InvokingClass() {
    cout << "Invoked by Drived\n";
}

int main() {
    Derived aDerived;
    Derived *pDerived = &aDerived;
    Base    *pBase = &aDerived;

    pBase->NameOf();
    pBase->InvokingClass();
    pDerived->NameOf();
    pDerived->InvokingClass();

}