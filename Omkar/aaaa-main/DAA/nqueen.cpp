#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, unordered_set<int>& col, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) continue;

        col.insert(c);
        posDiag.insert(r + c);
        negDiag.insert(r - c);
        board[r][c] = 'Q';

        backtrack(r + 1, n, board, res, col, posDiag, negDiag);

        col.erase(c);
        posDiag.erase(r + c);
        negDiag.erase(r - c);
        board[r][c] = '.';
    }
}

vector<vector<string>> solveNQueens(int n, int first_queen_col) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    unordered_set<int> col, posDiag, negDiag;

    col.insert(first_queen_col);
    posDiag.insert(0 + first_queen_col);
    negDiag.insert(0 - first_queen_col);
    board[0][first_queen_col] = 'Q';

    backtrack(1, n, board, res, col, posDiag, negDiag);  // Start with the second row

    return res;
}

int main() {
    int n = 8;
    int first_queen_col = 1;
    vector<vector<string>> solution = solveNQueens(n, first_queen_col);

    if (!solution.empty()) {
        vector<string> board = solution[0];
        for (const string& row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    return 0;
}