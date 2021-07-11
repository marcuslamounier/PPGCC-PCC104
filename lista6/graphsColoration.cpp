#include <iostream>
#include <vector>

using namespace std;

void printSolution (vector<int> colors){
    for (const &c : colors) cout << c << " ";
    cout << endl;
}

bool checkPosition (vector<vector<int>> &graph, int point, vector<int> colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i][point] == 1 && colors[i] == color) return false;
        if (graph[point][i] == 1 && colors[i] == color) return false;
    }
    return true;
}

int mColorGraph (vector<vector<int>> &graph, int mColors, int point, vector<int> colors, int &nSol) {
    if (mColors == 0) return 0;

    if (point == graph.size()) {
        nSol++;
        cout << "Solucao " << nSol << endl;
        printSolution(colors);
        cout << "-------------" << endl;
        return nSol;
    }

    for (int color = 1; color <= mColors; color++){
        if (checkPosition(graph, point, colors, color)) {
            int aux = colors[point];
            colors[point] = color;
            mColorGraph(graph, mColors, point + 1, colors, nSol);
            colors[point] = aux;
        }
    }
    return nSol;
}

int main () {

    vector<vector<int>> graph = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 }
    };

    cout << "Problema dos grafos m-coloraveis" << endl;

    int mColors;
    cout << "Digite o numero de cores do grafo: ";
    cin >> mColors;
    cout << endl;

    vector<int> colors(4, 0);
    int nSol = 0;
    int finalNSol = mColorGraph(graph, mColors, 0, colors, nSol);
    
    cout << "\nNumero de solucoes com " << mColors << " cores para o grafo fornecido: " << finalNSol;

    return 0;
}