#include <iostream>
#include <cstring>
#include <ctime>
#include<cstdlib>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5;i++)
    {
        int num = rand() % 100;
        cout << num << endl;
    }
}