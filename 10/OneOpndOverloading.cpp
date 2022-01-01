#include <iostream>
using namespace std;

class Point
{
private:
    int xpos;
    int ypos;

public:
    Point(int x = 0, int y = 0)
        : xpos(x), ypos(y)
    {
    }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point &operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    Point operator-()
    {
        return Point(-xpos, -ypos);
    }
    friend Point &operator--(Point &ref);
    friend Point operator~(const Point &ref);
};

Point &operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point operator~(const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}
int main()
{
    Point pos1(1, 2);
    pos1.ShowPosition();
    Point pos2 = -pos1;
    pos2.ShowPosition();
}