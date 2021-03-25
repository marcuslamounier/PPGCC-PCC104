#include <iostream>
#include <vector>

using namespace std;

int sequentialSearch2(vector<int> v, int k) {
    int n = v.size();
    v[n] = k;
    int i = 0;
    while (v[i] != k) {
        i++;
    }
    if (i < n) {
        return i;
    }
    else {
        return -1;
    }
}

int bruteForceStringMatch(string s, string key) {
    int n = s.length();
    int m = key.length();

    for (int i = 0; i <= (n-m); i++) {
        int j = 0;
        while ((j < m) && (key[j] == s[i+j])) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}