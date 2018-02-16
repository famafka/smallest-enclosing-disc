#include "point.h"

class segment{
    point a, b;
public:
    segment();
    segment(const point & a, const point & b);

    point middle() const;

    double length() const;
};
