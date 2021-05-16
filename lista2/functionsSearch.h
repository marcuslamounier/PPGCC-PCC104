#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

template <typename T1, typename T2>
int sequentialSearch2(T1 v, T2 K) {
    int n = v.size();
    v[n] = K;
    int i = 0;
    while (v[i] != K) i++;
    return (i < n) ? i : -1;
}