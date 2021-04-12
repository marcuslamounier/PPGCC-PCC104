#include <iostream>
#include <bits/stdc++.h>

using namespace std;
  
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

int getMobile(int a[], bool direction[], int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (direction[a[i]-1] == RIGHT_TO_LEFT && i!=0) {
            if (a[i] > a[i-1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
  
        if (direction[a[i]-1] == LEFT_TO_RIGHT && i!=n-1) {
            if (a[i] > a[i+1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
  
    return (mobile == 0 && mobile_prev == 0) ? 0 : mobile;
}

void printOnePerm(int a[], bool direction[], int n) {
    int mobile = getMobile(a, direction, n);
    int pos = searchArr(a, n, mobile);
  
    if (direction[a[pos - 1] - 1] ==  RIGHT_TO_LEFT) swap(a[pos-1], a[pos-2]);
    else if (direction[a[pos - 1] - 1] == LEFT_TO_RIGHT) swap(a[pos], a[pos-1]);
  
    for (int i = 0; i < n; i++) {
        if (a[i] > mobile) {
            if (direction[a[i] - 1] == LEFT_TO_RIGHT) direction[a[i] - 1] = RIGHT_TO_LEFT;
            else if (direction[a[i] - 1] == RIGHT_TO_LEFT) direction[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }
  
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int fact(int n){
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

void printPermutation(int n) {
    int v[n];
    bool direction[n];
  
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
        cout << v[i];
        if (i != n - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        direction[i] =  RIGHT_TO_LEFT;
    }

    for (int i = 1; i < fact(n); i++) {
        printOnePerm(v, direction, n);
    }
}