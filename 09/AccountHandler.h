#ifndef _ACCOUNT_HANDLER_H_
#define _ACCOUNT_HANDLER_H_

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
    BoundCheckArray<Account *> accArr;
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