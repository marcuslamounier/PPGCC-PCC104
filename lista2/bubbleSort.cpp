#include <iostream>
#include <vector>

using namespace std;

#include "functionsUtil.h"
#include "functionsSort.h"

int main() {
    
    vector<int> v = randomVector(10, 100);
    cout << "Vetor inicial:" << endl;
    printVector(v);

    v = bubbleSort(v);
    cout << "Vetor ordenado pelo metodo BubbleSort:" << endl;
    printVector(v);

    cout << endl;
    return 0;
}