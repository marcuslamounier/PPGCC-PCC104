#include <iostream>
#include <algorithm>

using namespace std;
  
bool l_to_r = true;
bool r_to_l = false;

int searchArr(int a[], int n, int inverse) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == inverse) {
            pos = i + 1;
        }
    }
    return pos;
}
  
int getinverse(int a[], bool dir[], int n) {
    int inverse_prev = 0, inverse = 0;
    for (int i = 0; i < n; i++) {
        if (dir[a[i]-1] == r_to_l && i!=0){
            if (a[i] > a[i-1] && a[i] > inverse_prev) {
                inverse = a[i];
                inverse_prev = inverse;
            }
        }

        if (dir[a[i]-1] == l_to_r && i!=n-1) {
            if (a[i] > a[i+1] && a[i] > inverse_prev) {
                inverse = a[i];
                inverse_prev = inverse;
            }
        }
    }
  
    return (inverse == 0 && inverse_prev == 0) ? 0 : inverse;
}
  
void printOnePerm(int a[], bool dir[], int n) {
    int inverse = getinverse(a, dir, n);
    int pos = searchArr(a, n, inverse);

    if (dir[a[pos - 1] - 1] ==  r_to_l) {
        swap(a[pos-1], a[pos-2]);  
    }
       
    else if (dir[a[pos - 1] - 1] == l_to_r) {
        swap(a[pos], a[pos-1]);
    }
  
    for (int i = 0; i < n; i++) {
        if (a[i] > inverse){
            if (dir[a[i] - 1] == l_to_r) {
                dir[a[i] - 1] = r_to_l;
            }
            else if (dir[a[i] - 1] == r_to_l) {
                dir[a[i] - 1] = l_to_r;
            }
                
        }
    }
  
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << " ";
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}
  
void printPermutation(int n) {
    int *a = new int (n);
    bool *dir = new bool (n);
  
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        cout << a[i];
    }
    cout << " ";

    for (int i = 0; i < n; i++) {
        dir[i] =  r_to_l;
    }
  
    for (int i = 1; i < fact(n); i++) {
        printOnePerm(a, dir, n);
    }
}
  
int main() {

    cout << "Permutacoes: " << endl;
    int n = 4;
    printPermutation(n);

    return 0;
}