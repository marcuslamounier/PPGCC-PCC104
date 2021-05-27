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
void quickSort (vector <T> &v, int l, int r) {

    int i = l;
    int j = r;

    T pivot = v[(l + r) / 2];
    while (i <= j) {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort (v, l, j);
    if (i < r) quickSort (v, i, r);
    
}

int main () {
    int n = 20;
    int minLim = 0;
    int maxLim = 100;

    // vector <int> v = randomVector (n, minLim, maxLim);
    vector <char> v = {'M','A','R','C','U','S',' ','V','I','N','I','C','I','U','S'};
    cout << "Lista: " << endl;
    printVector (v);

    cout << "Lista ordenada:" << endl;
    quickSort (v, 0, v.size() - 1);
    printVector (v);

    return 0;
}