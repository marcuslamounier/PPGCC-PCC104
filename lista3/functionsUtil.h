#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int compare (const void *a, const void * b) {
    return ( *(char *)a - *(char *)b );
} 
  
void swap (char* a, char* b) { 
    char t = *a; 
    *a = *b; 
    *b = t; 
} 

int searchArr(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (a[i] == mobile) return (i + 1);
    }
}

vector<int> randomVector(int tam, int maxNum) {
    vector<int> v;
    srand((unsigned)time(0));
    for (int i = 0; i < tam; i++) {
        v.push_back(rand() % maxNum);
    }
    return v;
}

template <typename T>
void printVector(T v) {
    for (const int& x : v) {
        cout << x << " ";
    }
    cout << endl;
}