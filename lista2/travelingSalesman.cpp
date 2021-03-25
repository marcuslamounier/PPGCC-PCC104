#include <iostream>
#include <vector>

#include "functionsGeometry.h"

using namespace std;

int main() {
    vector<vector<int>> cities = {
        { 0, 20, 42, 35 },
        { 20, 0, 30, 34 },
        { 42, 30, 0, 12 },
        { 35, 34, 12, 0 }
    };

    vector<vector<int>> state(cities.size());
    for(auto& neighbors : state)
        neighbors = vector<int>((1 << cities.size()) - 1, INT_MAX);

    cout << "Menor rota: " << tsp(cities, 0, 1, state) << endl;

    return 0;
}