#ifndef _ACCOUNT_HANDLER_H_
#define _ACCOUNT_HANDLER_H_

#include "Account.h"

class AccountHandler
{
private:
    Account *accArr[100];
    int accNum;

public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();

protected:
    void MakeNormalAccount();
    void MakeCreditAccount();
};

#endif