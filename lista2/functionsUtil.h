#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct POINT {
    double x, y;
};

struct ITEM {
    int value, weight;
    ITEM(int value, int weight): value(value), weight(weight){}
};

void printVector(vector<int> v) {
    for (const int& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void printPoint(POINT p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

vector<int> randomVector(int tam, int maxNum) {
    vector<int> v;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        v.push_back(rand() % maxNum);
    }
    return v;
}

vector<vector <int>> randomPoints(int tam, int maxNum, int dim) {
    vector<vector<int>> espaco;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        vector<int> ponto;
        for (int j = 0; j < dim; j++) {
            ponto.push_back(rand() % maxNum);
        }
        espaco.push_back(ponto);
    }
    return espaco;
}

vector<POINT> randomPoints(int tam, int maxNum) {
    vector<POINT> espaco;
    srand((unsigned)time(0));

    for (int i = 0; i < tam; i++) {
        POINT p;
        p.x = rand() % maxNum;
        p.y = rand() % maxNum;
        espaco.push_back(p);
    }

    return espaco;
}