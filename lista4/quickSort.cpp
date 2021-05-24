#include <iostream>
#include <vector>
#include <ctime>

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
void printVector(vector<T> v) {
    for (const T &x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
int partition(vector<T> &v, int l, int r){
    int pivot = v[r];
    int mark = l;
    int aux;

    for (int i = l; i < r; i++){
        if (v[i] <= pivot){
            aux = v[i];
            v[i] = v[mark];
            v[mark] = aux;
            mark++;
        }
    }
    
    aux = v[mark];
    v[mark] = v[r];
    v[r] = aux;

    return mark;
}

int partitionPair(vector<pair <int, int>> &v, int l, int r){
    int pivot = v[r].first;
    int mark = l;
    int aux;
    
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first << ", " << v[i].second << " - ";
        }
        cout << endl;

    for (int i = l; i < r; i++){
        if (v[i].first <= pivot){
            aux = v[i].first;
            v[i].first = v[mark].first;
            v[mark].first = aux;
            mark++;
        }
    }
    
    aux = v[mark].first;
    v[mark].first = v[r].first;
    v[r].first = aux;

    return mark;
}

template <typename T>
void quicksort(vector<T> &v, int l, int r){
    if (l < r) {
        int pivot = partition(v, l, r);
        quicksort(v, l, pivot - 1);
        quicksort(v, pivot + 1, r);
    }
}

void quicksortPair(vector<pair <int, int>> &v, int l, int r){
    if (l < r) {
        int pivot = partitionPair(v, l, r);
        quicksortPair(v, l, pivot - 1);
        quicksortPair(v, pivot + 1, r);
    }
}

int main(){

    // int n;
    // cout << "Digite n: ";
    // cin >> n;

    // int minLimit = 0;
    // int maxLimit = 20;

    // vector <int> v = randomVector(n, minLimit, maxLimit);

    vector<pair <int, int>> v;
    v.push_back(make_pair(1, 5));
    v.push_back(make_pair(3, 2));
    v.push_back(make_pair(5, 4));
    v.push_back(make_pair(6, 4));
    v.push_back(make_pair(1, 2));

    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << " - " << v[i].first << ", " << v[i].second << endl;
    }
    cout << endl;

    quicksortPair(v, 0, v.size() - 1);


    // vector<char> v = {'E','X','A','M','P','L','E'};

    
    

    // cout << "Vetor:" << endl;
    // printVector(v);
    
	// quicksort(v, 0, v.size() - 1);

	// cout << "Vetor ordenado: " << endl;
	// printVector(v);

	return 0;
}