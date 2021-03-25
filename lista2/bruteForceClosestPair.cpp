#include <iostream>
#include <vector>

#include "functionsGeometry.h"

using namespace std;


int main() {

    vector<POINT> espaco = randomPoints(5, 100);

    for (int i = 0; i < espaco.size(); i++) {
        cout << "Ponto " << i << " - ";
        printPoint(espaco[i]);
    }
    cout << endl;
    
    cout << "Menor distancia entre dois pontos: " << bruteForceClosestPair(espaco);

    cout << endl;
    return 0;
}

