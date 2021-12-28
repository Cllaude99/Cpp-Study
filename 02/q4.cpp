#include <iostream>

using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point&PntAdder(const Point&p1, const Point&p2)
{
    Point *x = new Point;
    x->xpos = p1.xpos + p2.xpos;
    x->ypos = p1.ypos + p2.ypos;
    return *x;
}

int main()
{
    Point *s1 = new Point;
    Point *s2 = new Point;

    s1->xpos = 1;
    s1->ypos = 2;

    s2->xpos = 3;
    s2->ypos = 4;

    Point &s3 = PntAdder(*s1, *s2);

    cout << s3.xpos << endl;
    cout << s3.ypos << endl;
    delete s1;
    delete s2;
    delete &s3;
}