#include <iostream>

using namespace std;

void combinacoes(int elements[], bool checkEl[], int i, int sizeEl) {
    if (i == sizeEl){
        cout << "[ ";
        for (int j = 0; j < sizeEl; j++) {
            if (checkEl[j]) {
                cout << elements[j] << " ";
            }
        }
        cout << "]";
        cout << endl;
    }
    else {
        checkEl[i] = true;
        combinacoes(elements, checkEl, i + 1, sizeEl);
        checkEl[i] = false;
        combinacoes(elements, checkEl, i + 1, sizeEl);
    }
}

int main() {
    int elements[] = { 1, 2, 3 };
    int sizeEl = sizeof(elements) / sizeof(int);
    bool *checkEl = new bool[sizeEl];

    for (int i = 0; i < sizeEl; i++) {
        checkEl[i] = false;
    }

    combinacoes(elements, checkEl, 0, sizeEl);

    return 0;
}