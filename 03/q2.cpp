#include <iostream>
using namespace std;

class Calculator
{
private:
    int addnum;
    int minnum;
    int mulnum;
    int divnum;
public:
    void Init();
    double Add(double n1, double n2);
    double Min(double n1, double n2);
    double Mul(double n1, double n2);
    double Div(double n1, double n2);
    void ShowOpCount();
};

void Calculator::Init()
{
    addnum = minnum = mulnum = divnum = 0;
}

double Calculator::Min(double n1, double n2)
{
    minnum += 1;
    return n1 - n2;
}

double Calculator::Mul(double n1, double n2)
{
    mulnum += 1;
    return n1 * n2;
}

double Calculator::Div(double n1, double n2)
{
    divnum += 1;
    return n1 / n2;
}

double Calculator::Add(double n1, double n2)
{
    addnum += 1;
    return n1 + n2;
}

void Calculator::ShowOpCount()
{
    cout << "µ¡¼À: " << addnum << " »¬¼À: " << minnum << " °ö¼À: " << mulnum << " ³ª´°¼À: " << divnum << endl;
}

int main()
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}