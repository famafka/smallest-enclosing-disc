#include <bits/stdc++.h>
#include "segment.h"

class circle{
    point c;
    double r;
public:
    circle();
    circle(const point & c, double r);
    circle(double x, double y, double r);

    circle(const point & a, const point & b, const point & c);
    circle(const point & a, const point & b);

    bool inside(const point &) const;

    void print() const;
};
