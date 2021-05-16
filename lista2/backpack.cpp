#include <iostream>

#include "functionsGeometry.h"
  
using namespace std;
  
int main() {
    int N = 90;
  
    ITEM arr[] = {
        { 100, 10 },
        { 280, 40 },
        { 120, 20 },
        { 280, 40 },
        { 120, 20 },
        { 280, 40 },
        { 120, 20 },
        { 280, 40 },
        { 120, 20 },
        { 120, 24 }
    };
  
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Lucro maximo: " << backpack(arr, N, size);
    return 0;
}