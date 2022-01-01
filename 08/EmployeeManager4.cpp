#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum
    {
        RISK_A = 3,
        RISK_B = 2,
        RISK_C = 1
    };
}

class Employee
{
private:
    char name[100];

public:
    Employee(const char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
    int salary;

public:
    PermanentWorker(const char *name, int money)
        : Employee(name), salary(money)
    {
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(const char *name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    {
    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(const char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {
    }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class ForeignSalesWorker : public SalesWorker
{
private:
    const int risk;

public:
    ForeignSalesWorker(const char *name, int money, double ratio, int risklevel)
        : SalesWorker(name, money, ratio), risk(risklevel)
    {
    }

    int GetPay() const
    {
        return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * risk * 0.1);
    }
    void ShowSalaryInfo() const
    {
        SalesWorker::ShowSalaryInfo();
        cout << "risk pay: " << SalesWorker::GetPay() * risk * 0.1 << endl;
        cout << "sum: " << GetPay() << endl
             << endl;
    }
};
class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler()
        : empNum(0)
    {
    }
    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
}