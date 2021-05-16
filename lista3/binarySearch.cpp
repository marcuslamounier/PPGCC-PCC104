#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int PesquisaBinaria (const vector<int> &v, const int key, int start, int finish) {
    int half = (start + finish) / 2;

    if (v[half] == key) {
        return half;
    }
    else if (start == finish) {
        return -1;
    }
    else {
        return (v[half] < key) ? PesquisaBinaria (v, key, half + 1, finish) : PesquisaBinaria (v, key, start, half - 1);
    }
}

int main() {
    int key;
	cout << "Numero a ser pesquisado: ";
	cin >> key;
    vector<int> v = { 2, 7, 9, 15, 20, 30, 50, 55, 66, 77, 99 };

    if (key < v[0] || key > v[v.size() -1]) {
        cout << "Elemento fora do range";
    }
    else {
        int pos = PesquisaBinaria(v, key, 0, v.size() - 1);
        if (pos == -1) {
            cout << "Nao encontrado";
        }
        else {
            cout << "Encontrado na posicao " << pos;
        }
    }
    return 0;
}