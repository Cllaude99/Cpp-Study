#include <iostream>

using namespace std;

void AddOne(int &ref)
{
    ref += 1;
}

void Change(int &ref)
{
    ref *= -1;
}

int main()
{
    int num = 10;

    cout << num << endl;
    AddOne(num);
    cout << num << endl;
    Change(num);
    cout << num << endl;
}