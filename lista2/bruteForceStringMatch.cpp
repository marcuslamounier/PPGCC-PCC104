#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "functionsSearch.h"

int main() {

    string s = "Lorem ipsum dolor sit amet";
    string k = "sit";

    int pos = bruteForceStringMatch(s, k);

    (pos == -1) ? (cout << "O conjunto nao foi encontrado") : (cout << "O conjunto vai da posicao " << pos << " a " << pos + k.length() - 1);

    cout << endl;
    return 0;
}

