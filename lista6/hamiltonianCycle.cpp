#include <iostream>
#include <vector>

using namespace std;

void printSolution (vector<int> colors){
    for (const &c : colors) cout << c << " ";
    cout << endl;
}

bool checkPosition (vector<vector<int>> &graph, int pos, int nextPoint, vector<int> path) {
    if (graph[path[pos - 1]][nextPoint] == 0) return false;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == nextPoint) return false;
    }
    return true;
}

int hamiltonCycles (vector<vector<int>> &graph, int pos, vector<int> path, int &nSol) {
    if (pos == graph.size()) {
        nSol++;
        cout << "Solucao " << nSol << endl;
        printSolution(path);
        cout << "-------------" << endl;
        return nSol;
    }

    for (int nextPoint = 1; nextPoint < graph.size(); nextPoint++){
        if (checkPosition(graph, pos, nextPoint, path)) {
            path[pos] = nextPoint;
            hamiltonCycles(graph, pos + 1, path, nSol);
            path[pos] = -1;
        }
    }
    return nSol;
}

int main () {

    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    cout << "Problema dos ciclos hamiltonianos nos grafos" << endl;

    vector<int> path(5, -1);
    path[0] = 0;
    int nSol = 0;
    int finalNSol = hamiltonCycles(graph, 1, path, nSol);
    
    cout << "\nNumero de ciclos hamiltonianos para o grafo fornecido: " << finalNSol;

    return 0;
}