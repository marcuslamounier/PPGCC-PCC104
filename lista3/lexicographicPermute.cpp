#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
  
// #include "lexicographicPermute.h"

void print_permutations (vector<vector<int>> &permutations) {
    for (vector<int> p : permutations) {
        for (int el : p) cout << el << " ";
        cout << endl;
    }
}

vector<vector<int>> lexic_permute (int n) {
    vector<vector<int>> permutations;
    vector<int> permutation;

    for (int i = 0; i < n; i++) {
        permutation.push_back(i + 1);
    }

    permutations.push_back(permutation);

    bool decreasing_order = false;

    do {
        int i = -1;
        for (int k = 0; k < n - 1; k++) {
            if (permutation[k] < permutation[k + 1]) {
                i = k;
            }
        }

        decreasing_order = (i == -1);

        if (!decreasing_order) {
            int j = i;
            for (int k = i; k < n; k++) {
                if (permutation[i] < permutation[k]) {
                    j = k;
                }
            }

            swap(permutation[i], permutation[j]);
            reverse(permutation.begin() + (i + 1), permutation.end());
            permutations.push_back(permutation);
        }

    } while (!decreasing_order);

    return permutations;
}


  
int main() { 

    int n = 4;
    vector<vector<int>> permutations = lexic_permute(n);

    print_permutations(permutations);

    return 0; 
} 