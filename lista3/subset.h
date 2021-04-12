#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void getSubsets(char str[]) {
    int size = strlen(str);
    vector<string> v;

    v.push_back("");
    v.push_back("abc");

    for (int i = 1; i <= size; i++) {
        for (int j = i - 1; j < size; j++) {
            // TO DO
        }
    }

    for (int i = 0; i < v.size(); i ++) {
        cout << "Subset " << i + 1 << ": " << v[i] << endl;
    }
}