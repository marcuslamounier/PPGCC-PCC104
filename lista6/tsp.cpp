#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
void printMatrix (vector<vector<T>> &m) {
    for (vector<T> &l : m) {
        for (T &c : l) cout << c << "\t";
        cout << endl;
    }
}

vector<vector<int>> readTspInstances (string tsp_file, int headLines, int instances) {

    string line;
    int val;
    int lineCounter = 0;

    ifstream inputFile(tsp_file);

    vector<vector<int>> tspMatrix (instances, vector<int> (instances, 0));

    while (inputFile) {
        getline(inputFile, line);
        lineCounter++;

        if (lineCounter > headLines && lineCounter <= headLines + instances) {

            int i = lineCounter - headLines - 1;
            int j = i + 1;

            stringstream stream(line);
            while (stream >> val) {
                tspMatrix[i][j] = val;
                tspMatrix[j][i] = val;
                j++;
            }
        }
    }

    return tspMatrix;
}

int main () {

    string tsp_file = "brazil58.tsp";

    int headLines = 7;
    int instances = 58;

    vector<vector<int>> tspMatrix = readTspInstances (tsp_file, headLines, instances);
    printMatrix(tspMatrix);


    return 0;
}