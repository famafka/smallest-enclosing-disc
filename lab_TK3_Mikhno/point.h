#include <bits/stdc++.h>

using namespace std;

class point{
    double x, y;
public:
    point();
    point(double x, double y);

    double getX() const;
    double getY() const;

    static double dist(const point &, const point &);

    static double triangleArea(const point &, const point &, const point &);
    static bool isClockwise(const point &, const point &, const point &);
    static bool isCounterClockwise(const point &, const point &, const point &);

    bool operator < (const point & oth) const;
    bool operator == (const point & oth) const;

    point operator - (const point & oth) const;
    point operator + (const point & oth) const;
    double operator * (const point & oth) const;
    point operator * (double a) const;

    void print() const;
};

double sqr(double a);
