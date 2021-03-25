#include <iostream>
#include <vector>
#include <string>

#include "functionsSearch.h"

using namespace std;


int main() {

    string s = "Lorem ipsum dolor sit amet";
    string k = "sum";

    int pos = bruteForceStringMatch(s, k);

    cout << "O conjunto vai da posicao " << pos << " a " << pos + k.length() - 1;

    cout << endl;
    return 0;
}

