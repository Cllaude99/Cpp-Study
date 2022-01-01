#ifndef _NORMAL_ACCOUNT_H__
#define _NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int ID, int money, const char *name, int rate)
        : Account(ID, money, name), interRate(rate)
    {
    }
    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money * (interRate / 100.0));
    }
};

#endif