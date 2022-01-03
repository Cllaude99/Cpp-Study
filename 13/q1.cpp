#include <iostream>
using namespace std;

template <class T>
void SwapData(T &x,T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point(int x=0,int y=0)
        :xpos(x),ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

int main()
{
    Point pos1(1, 2);
    Point pos2(3, 4);

    pos1.ShowPosition();
    pos2.ShowPosition();

    SwapData<Point>(pos1, pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
}