#include <iostream>

using namespace std;

void createMatrix(int A[100][100]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            A[i][j] = rand()%101;
        }
    }
}

void printMatrix(int A[100][100]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void strassen(int A[100][100], int B[100][100], int C[100][100]){
    int m1,m2,m3,m4,m5,m6,m7;
    m1 = (A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
    m2 = (A[1][0]+A[1][1])*(B[0][0]);
    m3 = (A[0][0])*(B[0][1]-B[1][1]);
    m4 = (A[1][1])*(B[1][0]-B[0][0]);
    m5 = (A[0][0]+A[0][1])*(B[1][1]);
    m6 = (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
    m7 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
    C[0][0] = m1+m4-m5+m7;
    C[0][1] = m3+m5;
    C[1][0] = m2+m4;
    C[1][1] = m1+m3-m2+m6;
}

int main() {
    int A[100][100] = {0};
    int B[100][100] = {0};
    int C[100][100] = {0};

    createMatrix(A);
    printMatrix(A);
    cout << endl;

    createMatrix(B);
    printMatrix(B);
    cout << endl;

    strassen(A,B,C);
    printMatrix(C);

    return 0;
}