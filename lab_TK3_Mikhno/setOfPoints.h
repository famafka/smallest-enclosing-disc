#include <bits/stdc++.h>
#include "cirlce.h"

class setOfPoints{
    vector <point> points;
public:

    setOfPoints(const vector <point> & points);
    setOfPoints();

    void addPoint(const point &);

    setOfPoints getConvexHull() const;

    circle getSmallestEnclDisc() const;
    circle getSmallestEnclDiscWithPoint(const point &) const;
    circle getSmallestEnclDiscWith2Points(const point &, const point &) const;

    void print() const;
};

