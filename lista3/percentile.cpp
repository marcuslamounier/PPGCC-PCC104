#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int LomutoPartition (vector <int> &v, int l, int r) {
    int pivot = v[l];
    int s = l;

    for (int i = l; i < r; i ++) {
        if (v[i] < pivot) {
            s++;
            swap(v[s], v[i]);
        }
    }
    swap(v[l], v[s]);

    return s;
}

int LomutoPartition (vector <int> &v) {
    return LomutoPartition(v, 0, v.size());
}

int quickSelect (vector <int> &a, int l, int r, int k) {
    int s = LomutoPartition(a, l, r);
    if (s == k) {
        return a[s];
    }
    else if (s > k) {
        return quickSelect (a, l, s, k);
    }
    else {
        return quickSelect (a, s + 1, r, k);
    }
}

int percentile (vector <int> v, double p) {
    int k = ceil((v.size() - 1) * p);
    return quickSelect(v, 0, v.size(), k);
}

int main () {
    vector <int> v = { 99, 64, 1, 5, 55, 34, 87, 94, 44, 12, 67, 11, 28 };
    double perc = 0.5;

    for (auto e : v) {
        cout << e << "\t";
    }
    cout << endl;

    int el = percentile(v, perc);
    vector<int>::iterator it = find(v.begin(), v.end(), el);
    int pos = distance(v.begin(), it);

    cout << "O elemento que divide " << perc * 100 << "% dos e o elemento " << el << ", na posicao " << pos << endl;

    return 0;
}