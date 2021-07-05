#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <limits>

using namespace std;

void initializeCoinVector (vector<int> &coinValues) {
    coinValues.push_back(1);
    coinValues.push_back(5);
    coinValues.push_back(10);
    coinValues.push_back(25);
    coinValues.push_back(50);
    coinValues.push_back(100);
}

template <typename T>
void printVector (vector<T> &v) {
    for (const &x : v) cout << x << " ";
    cout << endl;
}

template <typename T>
void printCurrency(T c) {
    cout << fixed << setprecision(2) << ((double) c) / 100;
}

template <typename T>
void printCoins (vector<T> &v) {
    for (const &x : v) {
        printCurrency(x);
        cout << " ";
    }
    cout << endl;
}

int changeMaking (int change, vector<int> &coinValues) {
    vector<int> F(change + 1, 0);

    int temp;
    int j;
    int m = coinValues.size();

    for (int i = 1; i <= change; i++) {
        temp = numeric_limits<int>::max();
        j = 0;
        while ((j < m) && (i >= coinValues[j])) {
            temp = min(F[i - coinValues[j]], temp);
            j++;
        }
        F[i] = temp + 1;
    }
    return F[change];
}

int main () {

    cout << "Change-making Problem" << endl;

    vector<int> coinValues;
    initializeCoinVector(coinValues);

    int change;
    cout << "Digite o valor de troco: ";
    cin >> change;
    cout << endl;

    // for (int i = 0; i <= change; i++) {
    //     printCurrency(i);
    //     cout << ": " << changeMaking(i, coinValues) << " moedas" << endl;
    // }

    cout << "Para um troco de ";
    printCurrency(change);
    cout << ", sao necessarias pelo menos " << changeMaking(change, coinValues) << " moedas" << endl;

    // printCoins(coinValues);


    return 0;
}