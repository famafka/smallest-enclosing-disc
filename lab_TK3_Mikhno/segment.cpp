#include "segment.h"

segment :: segment()
{
    a = point(0, 0);
    b = point(0, 0);
}

segment :: segment(const point & a, const point & b) : a(a), b(b)
{

}

point segment :: middle() const
{
    return point((a.getX() + b.getX()) / 2., (a.getY() + b.getY()) / 2.);
}

double segment :: length() const
{
    return point :: dist(a, b);
}
