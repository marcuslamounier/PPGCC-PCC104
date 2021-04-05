#include <vector>
#include <iostream>
#include <limits>
#include <math.h>
#include <stack>
#include <array>
#include <bits/stdc++.h>

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
 
        if ((y < ymin) || (ymin == y && espaco[i].x < espaco[min].x)) {
            ymin = espaco[i].y, min = i;
        }
    }
 
    swap(espaco[0], espaco[min]);

    p0 = espaco[0];
    qsort(&espaco[1], n - 1, sizeof(POINT), compare);
 
    stack<POINT> S;
    S.push(espaco[0]);
    S.push(espaco[1]);
    S.push(espaco[2]);

    for (int i = 3; i < n; i++) {
        while (orientation(nextToTop(S), S.top(), espaco[i]) != 2){
            S.pop();
        }
        S.push(espaco[i]);
    }

    vector<POINT> v;
 
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

// int *randomGraphs(int n, int maxDist, int v[]) {

//     cout << "abc";

//     int v[n];

//     for (int i = 0; i < n; i ++) {
//         cout << "Linha " << i << endl;
//         for (int j = i + 1; j < n; j++) {
//             v[i][j] = 1;
//             v[j][i] = 1;
//         }
//         v[i][i] = 0;
//     }

//     return v;
// }

int tsp(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state) {
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][0];

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < cities.size(); ++i) {
        if(i == pos || (visited & (1 << i)))
            continue;

        int distance = cities[pos][i] + tsp(cities, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}

bool cmp(struct ITEM a, struct ITEM b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
  
double backpack(struct ITEM arr[], int N, int size) {
    sort(arr, arr + size, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
  
    for (int i = 0; i < size; i++) {
        if (curWeight + arr[i].weight <= N) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else {
            int remain = N - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
  
    return finalvalue;
}