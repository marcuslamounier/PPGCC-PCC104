#include <iostream>

#include "functionsGeometry.h"

using namespace std;

int main() {
    vector<POINT> espaco = randomPoints(10, 50);

    int n = sizeof(espaco) / sizeof(espaco[0]);
    vector<POINT> convexPoints = convexHullPoints(espaco, n);

    cout << "Pontos da casca convexa:" << endl << "(x, y)" << endl;
    for (int i = 0; i < convexPoints.size(); i++) {
        printPoint(convexPoints[i]);
    }
    
    cout << "Perimetro da casca convexa: " << perimeter(convexPoints);

    cout << endl;
    return 0;
}