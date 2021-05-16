#include "permutations.h"

using namespace std;

// template <typename T> void print_vector(std::vector<T>& v);
// void generate_permutations(int n);

template <typename T> void print_vector(vector<T>& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void gp(vector<int>& current_path, vector<int>& to_do) {
    if (to_do.empty()) {
        print_vector(current_path);
    }
    else {
        for (int i = 0; i < to_do.size(); i++) {
            vector<int> path(current_path);
            path.push_back(to_do[i]);

            vector<int> left_to_do(to_do);
            left_to_do.erase(left_to_do.begin() + i);

            gp(path, left_to_do);
        }
    }
}

void generate_permutations (int n) {
    int startPoint = 1;
    vector<int> current_path = { startPoint };
    vector<int> to_do;
    for (int i = 0; i < n; i++) {
        to_do.push_back(i);
    }

    gp(current_path, to_do);
}

int main () {
    int n = 5;
    generate_permutations(n);


    return 0;
}