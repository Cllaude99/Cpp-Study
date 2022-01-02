#include <iostream>
using namespace std;

class First
{
private:
    int num1;
    int num2;

public:
    First(int n1 = 0, int n2 = 0)
        : num1(n1), num2(n2)
    {
    }
    void ShowData()
    {
        cout << num1 << ", " << num2 << endl;
    }
};

class Second
{
private:
    int num3;
    int num4;

public:
    Second(int n3 = 0, int n4 = 0)
        : num3(n3), num4(n4)
    {
    }
    void ShowData()
    {
        cout << num3 << ", " << num4 << endl;
    }
    Second &operator=(const Second &ref)
    {
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};