#include <vector>
#include <iostream>

using namespace std;

int interpolationSearch (vector<int> &v, int start, int finish, int key) {
    while (start <= finish && key >= v[start] && key <= v[finish]) {
        if (start == finish) {
            if (v[start] == key) return start;
            return -1;
        }
        int pos = start + (((finish - start) / (v[finish] - v[start])) * (key - v[start]));
 
        if (v[pos] == key) {
            return pos;
        }
        else {
            if (v[pos] < key) {
                start = pos + 1;
            }
            else {
                finish = pos - 1;
            }
        }
    }
    return -1;
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
        int pos = interpolationSearch (v, 0, v.size() -1, key);
        if (pos == -1) {
            cout << "Nao encontrado";
        }
        else {
            cout << "Encontrado na posicao " << pos;
        }
    }

    return 0;
}