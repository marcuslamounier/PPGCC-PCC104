#include "convexHull.h"

using namespace std;

vector<int> get_vals(int n, int maxNum) {
    vector<int> v;
    for (size_t i = 0; i < n; i++) v.push_back(rand()%maxNum);
    return v;
}

vector<vector<int>> get_convex_hull(vector<int> &x, vector<int> &y) {
    vector<vector<int>> segments;
    for (size_t i = 0; i < x.size(); i++) {
        for (size_t j = i + 1; j < x.size(); j++) {
            int a = y[j] - y[i];
            int b = x[i] - x[j];
            int c = x[i] * y[j] - y[i] * x[j];

            int current_sign = 0;
            bool sign_changed = false;

            for (size_t k = 0; k < x.size(); k++) {
                if (k != i && k != j) {
                    int sign = (a * x[k] + b * y[k] - c < 0) ? -1 : 1;
                    if (current_sign == 0) {
                        current_sign = sign;
                    }
                    else if (current_sign + sign == 0) {
                        sign_changed = true;
                        break;
                    }
                }
            }
            if (!sign_changed) segments.push_back({ x[i], y[i], x[j], y[j] });
        }
    }
    return segments;
}

void print_segments(vector<vector<int>> segments) {
    for (auto s : segments) {
        cout << "(" << s[0] << ", " << s[1] << "), (" << s[2] << ", " << s[3] << ")" << endl;
    }
}

int main() {
    int n = 20;
    int maxNum = 100;
    vector<int> x = get_vals(n, maxNum);
    vector<int> y = get_vals(n, maxNum);

    vector<vector<int>> segments = get_convex_hull(x, y);

    print_segments(segments);

    return 0;
}