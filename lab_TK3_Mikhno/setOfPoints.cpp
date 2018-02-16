#include "setOfPoints.h"

const double eps = 1e-9;

void setOfPoints :: addPoint(const point & a)
{
    points.push_back(a);
}

setOfPoints :: setOfPoints (const vector<point> &points) : points(points)
{

}

setOfPoints :: setOfPoints()
{

}

void setOfPoints :: print() const
{
    cout << points.size() << '\n';
    for(auto & p : points)
        p.print();
    cout << '\n';
}

setOfPoints setOfPoints :: getConvexHull() const
{
    vector <point> v(points);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    if(v.size() < 3)
        return setOfPoints(v);

    vector <point> UP, DOWN;

    UP.push_back(v[0]);
    DOWN.push_back(v[0]);

    for(int i = 1; i + 1 < v.size(); ++i)
        if(point :: isClockwise(v[0], v[i], v.back()))
            UP.push_back(v[i]);
        else
        if(point :: isCounterClockwise(v[0], v[i], v.back()))
            DOWN.push_back(v[i]);

    UP.push_back(v.back());
    DOWN.push_back(v.back());

    vector <point> realUp, realDown;

    for(int i = 0; i < UP.size(); ++i)
    {
        while(realUp.size() >= 2 && !point :: isClockwise(realUp[realUp.size() - 2], realUp[realUp.size() - 1], UP[i]))
            realUp.pop_back();

        realUp.push_back(UP[i]);
    }

    for(int i = DOWN.size() - 1; i >= 0; --i)
    {
        while(realDown.size() >= 2 && !point :: isClockwise(realDown[realDown.size() - 2], realDown[realDown.size() - 1], DOWN[i]))
            realDown.pop_back();

        realDown.push_back(DOWN[i]);
    }

    setOfPoints res;

    for(int i = 0; i < realUp.size(); ++i)
        res.addPoint(realUp[i]);

    for(int i = realDown.size() - 2; i > 0; --i)
        res.addPoint(realDown[i]);

    return res;
}

///

circle setOfPoints :: getSmallestEnclDiscWith2Points(const point & a, const point & b) const
{
    circle res(a, b);
    for(auto & p : points)
    {
        if(res.inside(p))
            continue;
        else
            res = circle(a, b, p);
    }
    return res;
}

circle setOfPoints :: getSmallestEnclDiscWithPoint(const point & a) const
{
    if(points.empty())
        return circle(a, 0);

    vector <int> P(points.size(), 0);
    for(int i = 1; i < P.size(); ++i)
        P[i] = i;
    random_shuffle(P.begin(), P.end());

    circle res(points[P[0]], a);

    setOfPoints s;
    s.addPoint(points[P[0]]);


    for(int i = 1; i < P.size(); ++i)
    {
        if(res.inside(points[P[i]]))
            s.addPoint(points[P[i]]);
        else
        {
            res = s.getSmallestEnclDiscWith2Points(a, points[P[i]]);
            s.addPoint(points[P[i]]);
        }
    }

    return res;
}

circle setOfPoints :: getSmallestEnclDisc() const
{
    if(points.empty())
        return circle(0, 0, 0);

    if(points.size() == 1)
        return circle(points[0], 0);

    vector <int> P(points.size(), 0);
    for(int i = 1; i < P.size(); ++i)
        P[i] = i;
    random_shuffle(P.begin(), P.end());

    circle res(points[P[0]], points[P[1]]);
    setOfPoints s;
    s.addPoint(points[P[0]]), s.addPoint(points[P[1]]);

    for(int i = 2; i < P.size(); ++i)
    {
        if(res.inside(points[P[i]]))
            s.addPoint(points[P[i]]);
        else
        {
            res = s.getSmallestEnclDiscWithPoint(points[P[i]]);
            s.addPoint(points[P[i]]);
        }
    }

    return res;
}
