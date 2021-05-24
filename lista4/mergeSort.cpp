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

template<class T>
void merge(vector<T>& v, int l, int m, int r) {

    int size1 = m - l + 1;
    int size2 = r - m;
    vector<T> L(size1);
    vector<T> R(size2);

    for(int i = 0; i < size1; i++) {
        L[i] = v[l + i];
    }
    for(int j = 0; j < size2; j++) {
        R[j] = v[m + j + 1];
    }

    int i = 0, j = 0;
    int k;
    for(k = l; k <= r && i < size1 && j < size2; k++) {
        if(L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
    }

    for(i = i; i < size1; ++i) {
        v[k] = L[i];
        k++;
    }

    for(j = j; j < size2; j++) {
        v[k] = R[j];
        k++;
    }
}

template<class T>
void merge_sort(vector<T> &v, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main(){
    // int vSize = 20;
    // int maxNum = 100;

    // vector<int> v = randomVector(vSize, maxNum);
    vector<char> v = {'E','X','A','M','P','L','E'};
    
	cout << "Vetor: " << endl;;
    printVector(v);

	merge_sort(v, 0, v.size() - 1);

	cout << "Vetor ordenado: " << endl;
    printVector(v);

    return 0;
}