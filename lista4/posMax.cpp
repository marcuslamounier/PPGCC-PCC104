#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> randomVector(int tam, int maxNum) {
    vector<int> v;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        v.push_back(rand() % maxNum);
    }
    return v;
}

template <typename T>
void printVector(vector<T> v) {
    for (const T &x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
int posMax(vector<T> &v, T el){
    for (int i = 0; i < v.size(); i++){
        if (el == v[i]){
            return i;
        }
    }
    return -1;
}


template <typename T>
int maxEl(vector<T> &v, int l, int r) {
    if (r - l <= 1) {
        return max(v[l], v[r]);
    } else {
        int m = (l + r) / 2;
        int n1 = maxEl(v, l, m);
        int n2 = maxEl(v, m + 1, r);
        return max (n1, n2);
    }
}

int main() {
    int vSize = 15;
    int maxNum = 50;

    // vector<int> v = randomVector(vSize, maxNum);
    vector<int> v = { 1, 2, 3, 4, 5, 6, 200, 200, 50, 200, 51, 54};
    printVector(v);

    int max_el = maxEl(v, 0, v.size() - 1);

    cout << "O maior elemento e " << max_el << " e esta na posicao " << posMax(v, max_el) << " do vetor";
    return 0;
}