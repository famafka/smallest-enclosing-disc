#include "point.h"

const long double eps = 1e-9;

point :: point()
{
    x = y = 0;
}

point :: point(double x, double y) : x(x), y(y)
{

}

double point :: getX() const
{
    return x;
}

double point :: getY() const
{
    return y;
}

///

bool point :: operator < (const point & oth) const
{
    return make_pair(x, y) < make_pair(oth.getX(), oth.getY());
}

bool point :: operator == (const point & oth) const
{
    return point :: dist(*this, oth) < eps;
}

point point :: operator + (const point & oth) const
{
    return point(x + oth.getX(), y + oth.getY());
}

point point :: operator - (const point & oth) const
{
    return point(x - oth.getX(), y - oth.getY());
}

point point :: operator * (double a) const
{
    return point(x * a, y * a);
}

double point :: operator * (const point & oth) const
{
    return x * oth.getX() + y * oth.getY();
}

///

double sqr(double a)
{
    return a * a;
}

double point :: dist(const point & a, const point & b)
{
    return sqrt(sqr(a.getX() - b.getX()) + sqr(a.getY() - b.getY()));
}

double point :: triangleArea (const point & a, const point & b, const point & c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool point :: isClockwise (const point & a, const point & b, const point & c)
{
    return triangleArea(a, b, c) < -eps;
}

bool point :: isCounterClockwise (const point & a, const point & b, const point & c)
{
    return triangleArea(a, b, c) > eps;
}

void point :: print() const
{
    cout.precision(3);
    cout << fixed << x << ' ' << y << '\n';
}
