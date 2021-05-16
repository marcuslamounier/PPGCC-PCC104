#include <iostream>
#include <vector>
#include <numeric>
#include <time.h>

using namespace std;

template <typename T> void print_vector(vector<T>& v, int maxColsPrint) {
    int j = 0;
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << ' ';
        j++;
        if (j % maxColsPrint == 0) {
            cout << endl;
        };
	}
	cout << endl;
}

int fakeCoinDetector (const vector<int>& coins, int begin, int end) {

	int fakeCoin = -1;

	if ((end - begin) == 1) {
		return begin;
	}
	else if ((end - begin) == 2) {
		return (coins[begin] < coins[begin + 1]) ? begin : begin + 1;
	}
	else {
		int pile_size = (end - begin) / 3;
		int remainder = (end - begin) % 3;

		int begin_p1;
		int begin_p2;
		int begin_p3;

		if (remainder == 0) {
			begin_p1 = begin;
			begin_p2 = begin + pile_size;
			begin_p3 = begin + 2 * pile_size;
		}
		else {
			begin_p1 = begin;
			begin_p2 = begin + pile_size + 1;
			begin_p3 = begin + 2 * pile_size + 2;
		}

		int weight_p1 = accumulate(coins.begin() + begin_p1, coins.begin() + begin_p2, 0);
		int weight_p2 = accumulate(coins.begin() + begin_p2, coins.begin() + begin_p3, 0);


		if (weight_p1 == weight_p2) {
			fakeCoin = fakeCoinDetector(coins, begin_p3, end);
		}
		else if (weight_p1 < weight_p2) {
			fakeCoin = fakeCoinDetector(coins, begin_p1, begin_p2);
		}
		else {
			fakeCoin = fakeCoinDetector(coins, begin_p2, begin_p3);
		}

	}

	return fakeCoin;
}


int main() {
    int maxColsPrint = 50;

    int maxNum = 200;
    srand (time(NULL));
    int posFakeCoin = rand() % maxNum;

	vector<int> coins(maxNum,3);
	coins[posFakeCoin] = 1;

	print_vector(coins, maxColsPrint);

    cout << "Moeda falsa encontrada na posicao " << fakeCoinDetector(coins, 0, coins.size()) << endl;

	return 0;
}