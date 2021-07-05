#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printMatrix (vector<vector<T>> &m) {
    for (vector<T> &l : m) {
        for (T &c : l) cout << "\t" << c << " ";
        cout << endl;
    }
}

template <typename T>
void initializeBoard (vector<vector<T>> &F, vector<vector<T>> &board) {
    for (vector<T> &l : board) {
        vector<T> f;
        for (T &c : l) f.push_back(0);
        F.push_back(f);
    }
}

template <typename T>
int coinCollectingUsual (vector<vector<T>> &board, int n, int m) {
    if (n == 0 && m == 0) return board[n][m];
    else if (n == 0) {
        return (coinCollectingUsual(board, n, m - 1) + board[n][m]);
    }
    else if (m == 0) {
        return (coinCollectingUsual(board, n - 1, m) + board[n][m]);
    }
    else {
        return (max(coinCollectingUsual(board, n, m - 1), coinCollectingUsual(board, n - 1, m)) + board[n][m]);
    }
}

template <typename T>
int coinCollectingDP (vector<vector<T>> &board) {

    vector<vector<T>> F;    
    initializeBoard(F, board);

    F[0][0] = board[0][0];

    int n = board.size();
    int m = board[0].size();

    // 1a coluna
    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + board[i][0];
    }

    // 1a linha
    for (int i = 1; i < m; i++) {
        F[0][i] = F[0][i - 1] + board[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            F[i][j] = max((F[i - 1][j]), (F[i][j - 1])) + board[i][j];
        }
    }

    return F[n - 1][m - 1];
}

int main() {

    vector<std::vector<int>> board(
        {
            {0, 0, 0, 0, 1, 0},
            {0, 1, 0, 1, 0, 0},
            {4, 0, 0, 1, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {1, 2, 0, 0, 1, 0}
        }
    );


    printMatrix(board);

    cout << "Maior quantidade de moedas coletadas: " << coinCollectingUsual(board, board.size() - 1, board[0].size() - 1) << endl;

    return 0;
}