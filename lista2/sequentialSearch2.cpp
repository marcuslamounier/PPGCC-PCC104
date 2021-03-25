#include <iostream>
#include <vector>

using namespace std;

#include "functionsUtil.h"
#include "functionsSearch.h"

int main() {
    
    vector<int> v = { 32, 94, 45, 24, 27, 55, 85, 51, 53, 76 };
    cout << "Vetor inicial:" << endl;
    printVector(v);

    int chave = 27;
    cout << "O elemento " << chave << " esta na posicao " << sequentialSearch2(v, chave) << endl;

    cout << endl;
    return 0;
}

