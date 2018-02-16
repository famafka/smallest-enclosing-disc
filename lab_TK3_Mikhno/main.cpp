#include <bits/stdc++.h>
#include "setOfPoints.h"

using namespace std;

int main(int argc, char * argv[])
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    setOfPoints s;
    for(int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        s.addPoint(point(x, y));
    }

    s.getConvexHull().print();
    s.getSmallestEnclDisc().print();
}
