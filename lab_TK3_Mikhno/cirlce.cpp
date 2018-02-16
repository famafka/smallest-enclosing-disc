#include "cirlce.h"

const double eps = 1e-9;

bool circle :: inside(const point & a) const
{
    return r + eps > point :: dist(a, c);
}

circle :: circle()
{

}

circle :: circle(const point & c, double r) : c(c), r(r)
{

}

circle :: circle(double x, double y, double r) : r(r)
{
    c = point(x, y);
}

void circle :: print() const
{
    cout.precision(3);
    c.print();
    cout << fixed << r << '\n';
}

circle :: circle(const point & a, const point & b, const point & c)
{
    double S = abs(point :: triangleArea(a, b, c)) / 2.;
    double d = S * S * 8.;

    double AA = sqr(segment(b, c).length()) / d * ((a - b) * (a - c));
    double BB = sqr(segment(a, c).length()) / d * ((b - a) * (b - c));
    double CC = sqr(segment(a, b).length()) / d * ((c - a) * (c - b));

    this -> c = point(((a * AA) + (b * BB) + (c * CC)));
    r = segment(a, b).length() * segment(b, c).length() * segment(a, c).length() / (4 * S);
}


circle :: circle(const point & a, const point & b)
{
    c = segment(a, b).middle();
    r = point :: dist(a, c);
}
