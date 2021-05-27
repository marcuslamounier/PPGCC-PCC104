#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector <int> randomVector (int tam, int minLimit, int maxLimit) {
    vector <int> v;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        v.push_back((rand() % maxLimit) - minLimit);
    }
    return v;
}

template <typename T>
void printVector (vector <T> v) {
    for (const T &x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
T insertionSort (T &v) {
    for (int i = 1; i < v.size(); i++) {
        int val = v[i];
        int j = i - 1;
        while ((j >= 0) && (val < v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        if (j != (i - 1)) v[j + 1] = val;
    }
    return v;
}

int main () {
    int n = 20;
    int minLim = 0;
    int maxLim = 100;

    vector <int> v = randomVector (n, minLim, maxLim);
    // vector <char> v = {'M','A','R','C','U','S',' ','V','I','N','I','C','I','U','S'};
    cout << "Lista: " << endl;
    printVector (v);

    cout << "Lista ordenada:" << endl;
    
    printVector (insertionSort (v));

    return 0;
}