#include <iostream>
#include <cstring>
using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException
{
private:
    int reqDep;
public:
    DepositException(int money)
        :reqDep(money)
    { }
    void ShowExceptionReason()
    {
        cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
    }
};

class WithdrawException : public AccountException
{
private:
    int balance;
public:
    WithdrawException(int money)
        :balance(money)
    { }
    void ShowExceptionReason()
    {
        cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���]" << endl;
    }
};

class Account
{
private:
    char accNum[50];
    int balance;
public:
    Account(const char*acc,int money)
        :balance(money)
    {
        strcpy(accNum, acc);
    }
    void Deposit(int money) throw(AccountException)
    {
        if(money<0)
            throw DepositException(money);
        balance += money;
    }
    void Withdraw(int money) throw(AccountException)
    {
        if(money>balance)
            throw WithdrawException(balance);
        balance -= money;
    }
    void ShowMyMoney()
    {
        cout << "�ܰ�: " << balance << endl
             << endl;
    }
};