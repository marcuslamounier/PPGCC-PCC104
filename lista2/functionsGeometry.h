#include <vector>
#include <iostream>
#include <limits>
#include <math.h>
#include <stack>

#include "functionsUtil.h"

using namespace std;

double distPoints(POINT a, POINT b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double bruteForceClosestPair(vector<POINT> v) {
    double d = numeric_limits<double>::infinity();
    int n = v.size() - 1;
    for (int i = 1; i < n; i++) {
        for (int j = (i + 1); j <= n; j++) {
            double dist = distPoints(v[i], v[j]);
            d = (d < dist) ? d : dist;
        }
    }
    return d;
}
 
POINT p0;
 
POINT nextToTop(stack<POINT> &S) {
    POINT p = S.top();
    S.pop();
    POINT res = S.top();
    S.push(p);
    return res;
}
 
void swap(POINT &p1, POINT &p2) {
    POINT temp = p1;
    p1 = p2;
    p2 = temp;
}
 
int dist(POINT p1, POINT p2) {
    return pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
}
 
int orientation(POINT p, POINT q, POINT r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
 
int compare(const void *vp1, const void *vp2) {
    POINT *p1 = (POINT *) vp1;
    POINT *p2 = (POINT *) vp2;
 
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
 
    return (o == 2) ? -1 : 1;
}
 
vector<POINT> convexHullPoints(vector<POINT> espaco, int n) {

    int ymin = espaco[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = espaco[i].y;
 
        // Pick the bottom-most or chose the left most point in case of tie
        if ((y < ymin) || (ymin == y && espaco[i].x < espaco[min].x)) {
            ymin = espaco[i].y, min = i;
        }
    }
 
    // Place the bottom-most point at first position
    swap(espaco[0], espaco[min]);
 
    // Sort n-1 points with respect to the first point.  A point p1 comes
    // before p2 in sorted ouput if p2 has larger polar angle (in
    // counterclockwise direction) than p1
    p0 = espaco[0];
    qsort(&espaco[1], n - 1, sizeof(POINT), compare);
 
    // Create an empty stack and push first three points to it.
    stack<POINT> S;
    S.push(espaco[0]);
    S.push(espaco[1]);
    S.push(espaco[2]);

    // Process remaining n-3 points
    for (int i = 3; i < n; i++) {
        while (orientation(nextToTop(S), S.top(), espaco[i]) != 2){
            S.pop();
        }
        S.push(espaco[i]);
    }

    vector<POINT> v;
 
    // Now stack has the output points, print contents of stack
    while (!S.empty()) {
        POINT p = S.top();
        v.push_back(p);
        S.pop();
    }

    return v;
}
 
double perimeter(vector<POINT> v) {
    double p = 0;
    int n = v.size();

    for (int i = 0; i < n-1; i++) {
        p += distPoints(v[i], v[i+1]);
    }
    p += distPoints(v[n-1], v[0]);

    return p;
}