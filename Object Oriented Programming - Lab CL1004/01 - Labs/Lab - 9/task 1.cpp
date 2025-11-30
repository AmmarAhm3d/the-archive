#include "one.h"

int main()
{
    Square s;
    s.setLength(5);
    cout << "Total Square Area: " << s.getArea() << "\n";
    Painting p1;
    cout << "Total paint cost: $" << p1.getCost(s.getArea()) << "\n";


    Rectangle r;
    r.setLength(5), r.setBreadth(7);
    cout << "Total Rectangle Area: " << r.getArea() << "\n";
    Painting p2;
    cout << "Total paint cost: $" << p2.getCost(r.getArea()) << "\n";

    Triangle t;
    t.setBreadth(30), t.setHeight(2);
    cout << "Total Triangle Area: " << t.getArea() << "\n";
    Painting p3;
    cout << "Total paint cost: $" << p3.getCost(t.getArea()) << "\n";

    return 0;
}