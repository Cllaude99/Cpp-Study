#include <iostream>
using namespace std;

class Point
{
private:
    int xpos;
    int ypos;

public:
    Point(int x, int y)
        : xpos(x), ypos(y)
    {
    }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point mid;
    int rad;

public:
    Circle(int x, int y, int r)
        : mid(x, y), rad(r)
    {
    }
    void ShowCircleInfo() const
    {
        cout << "radius: " << rad << endl;
        mid.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle c1;
    Circle c2;

public:
    Ring(int inX, int inY, int inR, int OutX, int OutY, int OutR)
        : c1(inX, inY, inR), c2(OutX, OutY, OutR)
    {
    }

    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        c1.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        c2.ShowCircleInfo();
    }
};

int main()
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}