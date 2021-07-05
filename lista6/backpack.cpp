#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector (vector<T> &v) {
    for (const &x : v) cout << "\t" << x << " ";
    cout << endl;
}

template <typename T>
void printMatrix (vector<vector<T>> &m) {
    for (vector<T> &l : m) {
        for (T &c : l) cout << "\t" << c << " ";
        cout << endl;
    }
}

int knapsackDP(vector<vector<int>> &items, vector<vector<int>> &F, int n, int capacity) {

    int aux;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            aux = knapsackDP(items, F, i - 1, j);
            if (j < items[0][i - 1]) {
                F[i][j] = aux;
            }
            else {
                F[i][j] = max(aux, items[1][i - 1] + knapsackDP(items, F, i - 1, j - items[0][i - 1]));
            }
        }
    }

    return F[n][capacity];

}

int knapsack (vector<vector<int>> &items, int capacity) {
    int n = items[0].size();
    vector<vector<int>> F;

    vector<int> f1(capacity + 1, 0);
    F.push_back(f1);

    vector<int> f2(capacity + 1, -1);
    f2[0] = 0;

    for (int i = 1; i <= n; i++) F.push_back(f2);

    return knapsackDP(items, F, n, capacity);
}

int main () {

    vector<vector<int>> items = {
        {17, 15, 12, 4, 5}, // pesos dos itens
        {40, 33, 20, 14, 22} // valores dos itens
    };

    int capacity = 30;

    cout << "Problema da Mochila" << endl;
    cout << "Capacidade da mochila " << capacity << endl;
    cout << "Itens disponiveis: " << endl;

    for (int i = 0; i < items[0].size(); i++) {
        cout << "\t" << i; 
    }
    cout << endl;
    
    cout << "Peso";
    printVector(items[0]);
    
    cout << "Valor";
    printVector(items[1]);

    cout << "Valor maximo da mochila: " << knapsack(items, capacity);

    return 0;
}