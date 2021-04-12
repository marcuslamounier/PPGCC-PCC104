#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T insertionSort(T v) {
    for (int i = 1; i < v.size() - 1; i++) {
        int valor = v[i];
        int j = i - 1;
        do {
            v[j + 1] = v[j];
            j--;
        } while (j >= 0 && v[j] > valor);
        v[j + 1] = valor;
    }
    return v;
}