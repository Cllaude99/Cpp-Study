#include <iostream>
using namespace std;

class Person
{
public:
    void Sleep()
    {
        cout << "Sleep" << endl;
    }
};

class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }
};
