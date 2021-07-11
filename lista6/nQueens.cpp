#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printBoard (vector<vector<T>> &m) {
    for (vector<T> &l : m) {
        for (T &c : l)  {
            cout << "\t" << (c == 0 ? '-' : 'X');
        }
        cout << endl;
    }
}

vector<vector<int>> initializeBoard (int boardSize) {
    vector<vector<int>> board;
    for (int i = 0; i < boardSize; i++) {
        vector<int> row (boardSize, 0);
        board.push_back(row);
    }
    return board;
}

bool checkPosition (vector<vector<int>> &board, int boardSize, int row, int col) {

    int i, j;

    // teste da linha ou coluna
    for (i = 0; i < boardSize; i++) {
        if (board[row][i] == 1 || board[i][col] == 1) {
            return false;
        }
    }

    // teste da diagonal principal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (i = row, j = col; i < boardSize && j < boardSize; i++, j++) {
        if (board[i][j] == 1) return false;
    }

    // teste da diagonal secundaria
    for (i = row, j = col; i >= 0 && j < boardSize; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    for (i = row, j = col; i < boardSize && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

int nQueens (vector<vector<int>> &board, int boardSize, int col, int &nSol) {
    if (col == boardSize) {
        nSol++;
        cout << "Solucao " << nSol << endl;
        printBoard(board);
        cout << "-------------" << endl;
        return nSol;
    }
    for (int i = 0; i < boardSize; i++){
        if (checkPosition(board, boardSize, i, col)) {
            board[i][col] = 1;
            nQueens(board, boardSize, col + 1, nSol);
            board[i][col] = 0;
        }
    }
    return nSol;
}


int main () {

    cout << "Problema das n-Rainhas" << endl;

    int boardSize;
    cout << "Digite a medida do tabuleiro: ";
    cin >> boardSize;
    cout << endl;

    vector<vector<int>> board = initializeBoard(boardSize);
    
    int nSol = 0;
    int finalNSol = nQueens(board, boardSize, 0, nSol);

    cout << "\nNumero de solucoes para um tabuleiro " << boardSize << "x" << boardSize << ": " << finalNSol;

    return 0;
}