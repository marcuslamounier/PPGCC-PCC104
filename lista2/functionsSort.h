#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
T bubbleSort(T v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j+1] < v[j])  {
                swap(v[j], v[j+1]);
            }
        }
    }
    return v;
}

template <typename T>
T selectionSort(T v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                min = j;
            }
            swap(v[i], v[min]);
        }
    }
    return v;
}