#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T bubbleSort(T v) {
  for (int passnum = v.size()-1; passnum > 0; passnum--) {
      for (int i = 0; i < passnum; i++) {
          if (v[i] > v[i+1]) {
              int temp = v[i];
              v[i] = v[i+1];
              v[i+1] = temp;
          }
      }
  }
  return v;
}

template <typename T>
T selectionSort(T v) {
    for (int fillslot = v.size()-1; fillslot >= 0; fillslot--) {
        int positionOfMax = 0;
        for (int location = 1; location < fillslot + 1; location++) {
            if (v[location] > v[positionOfMax]) {
                positionOfMax = location;
            }
        }

        int temp = v[fillslot];
        v[fillslot] = v[positionOfMax];
        v[positionOfMax] = temp;
    }
    return v;
}