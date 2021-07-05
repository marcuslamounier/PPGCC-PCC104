#include <iostream>
#include <vector>

using namespace std;

int fibonacciUsual (int n) {
    if (n <= 1) return n;
    return (fibonacciUsual(n - 1) + fibonacciUsual(n - 2));
}

template <typename T>
void printVector (vector<T> &v) {
    for (const &x : v) cout << x << " ";
    cout << endl;
}

void initializeArray (vector<int> &v, int n) {
    for (int i = 0; i <= n; i++) {
        (i <= 1) ? v.push_back(i) : v.push_back(-1);
    }
}

int fibonacciDP (int n, vector<int> &v) {
    if (v[n] == -1) {
        v[n] = fibonacciDP((n - 1), v) + fibonacciDP((n - 2), v);
    }
    return v[n];
}

int main () {

    cout << "Sequencia de Fibonacci: Fib (n) = Fib (n - 1) + Fib (n - 2)" << endl;

    int n;
    cout << "Digite o valor de n: " ;
    cin >> n;

    // Fibonacci sem programacao dinamica
    // cout << "Fib(" << n << ") = " << fibonacciUsual(n);

    // Fibonacci com programacao dinamica
    vector<int> v;
    initializeArray(v, n);
    cout << "Fib(" << n << ") = " << fibonacciDP(n, v) << endl;


    return 0;
}