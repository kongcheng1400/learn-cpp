#include <iostream>
using namespace std;

class Account
{
public:
    Account(double d) { _balance = d; }
    virtual ~Account() {}
    virtual double GetBalance() { return _balance; }
    virtual void PrintBalance() { cerr << "Err,balance not available for base class!" << endl; }

private:
    double _balance{0};
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(double d) : Account(d) {}
    void PrintBalance() override { cout << "checking account balance: " << GetBalance() << endl; }
};

class SavingAccount : public Account
{
public:
    SavingAccount(double d) : Account(d) {}
    void PrintBalance() override { cout << "Saving account balance: " << GetBalance() << endl; }
};

int main()
{
    CheckingAccount checking(100.00);
    SavingAccount savings(10000.00);

    Account *pAccount = &checking;
    pAccount->PrintBalance();

    pAccount = &savings;
    pAccount->PrintBalance();

    CheckingAccount *pChecking = new CheckingAccount(100.00);

    pChecking->Account::PrintBalance(); //  Explicit qualification.

    Account *pAccount = pChecking; // Call Account::PrintBalance

    pAccount->Account::PrintBalance(); //  Explicit qualification.
}