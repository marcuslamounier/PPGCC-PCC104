#include <iostream>
#include <vector>

#include "functionsGeometry.h"

using namespace std;

int main() {
    vector<vector<int>> cities = {
        { 0, 11, 22, 33 },
        { 11, 0, 16, 28 },
        { 22, 16, 0, 39 },
        { 33, 28, 39, 0 }
    };

    vector<vector<int>> state(cities.size());
    for(auto& neighbors : state)
        neighbors = vector<int>((1 << cities.size()) - 1, INT_MAX);

    cout << "Menor rota: " << tsp(cities, 0, 1, state) << endl;

    return 0;
}