#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector <int> randomVector(int tam, int minLimit, int maxLimit) {
    vector<int> v;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        v.push_back((rand() % maxLimit) - minLimit);
    }
    return v;
}

template <typename T>
void printVector(T v) {
    for (const int& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

vector <int> MinMaxHalf (vector <int> v, int minLimit, int maxLimit) {

    vector <int> minmax = { maxLimit + 1, minLimit - 1 };
    bool remain = ((v.size() % 2 )!= 0);
    int n = (remain) ? (v.size() - 1) : v.size();

    for (int i = 0; i < (n - 1); i+=2) {
        if (v[i] < v[i + 1]) {
            if (v[i] < minmax[0]) minmax[0] = v[i];
            if (v[i + 1] > minmax[1]) minmax[1] = v[i + 1];
        }
        else {
            if (v[i + 1] < minmax[0]) minmax[0] = v[i + 1];
            if (v[i] > minmax[1]) minmax[1] = v[i];
        }
    }

    if (remain) {
        if (v[n] < minmax[0]) minmax[0] = v[n];
        if (v[n] > minmax[1]) minmax[1] = v[n];
    }

    return minmax;
}



pair<int, int> MinMaxDC(vector<int> &v, int l, int r) {
    if (l == r) {
        return make_pair(l, l);
    }

    int m = l + (r - l) / 2;
    pair <int, int> v1 = MinMaxDC(v, l, m);
    pair <int, int> v2 = MinMaxDC(v, m + 1, r);

    int minEl = (v[v1.first] < v[v2.first]) ? v1.first : v2.first;
    int maxEl = (v[v1.second] > v[v2.second]) ? v1.second : v2.second;
    
    return make_pair(minEl, maxEl);
}

vector <int> MinMaxFB (vector <int> v, int minLimit, int maxLimit) {
    vector <int> minmax = { maxLimit + 1, minLimit - 1 };
    int n = v.size();

    for (int i = 0; i < n; i++) {
        if (v[i] < minmax[0]) minmax[0] = v[i];
        if (v[i] > minmax[1]) minmax[1] = v[i];
    }

    return minmax;
}

int main () {
    int n;
    cout << "Digite n: ";
    cin >> n;

    int minLimit = 0;
    int maxLimit = 20;

    vector <int> v = randomVector(n, minLimit, maxLimit);

    printVector(v);

    // vector <int> minmax = MinMaxHalf(v, minLimit, maxLimit);
    // vector <int> minmax = MinMaxFB(v, minLimit, maxLimit);
    pair <int, int> minmax = MinMaxDC(v, 0, v.size() - 1);
    

    // cout << "Menor: " << minmax[0] << endl;
    // cout << "Maior: " << minmax[1] << endl;

    cout << "Menor: " << v[minmax.first] << " na posicao " << minmax.first << endl;
    cout << "Maior: " << v[minmax.second] << " na posicao " << minmax.second << endl;



    
    return 0;
}