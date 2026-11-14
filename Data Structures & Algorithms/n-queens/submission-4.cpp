class Solution {
   public:
    vector<vector<string>> result;
    unordered_set<int> column;
    unordered_set<int> diagonal;
    unordered_set<int> antiDiagonal;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return result;
    }

    void solve(vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (column.find(col) == column.end() && diagonal.find(col + row) == diagonal.end() &&
                antiDiagonal.find(row - col) == antiDiagonal.end()) {
                column.insert(col);
                diagonal.insert(row + col);
                antiDiagonal.insert(row - col);
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
                column.erase(col);
                diagonal.erase(row + col);
                antiDiagonal.erase(row - col);
            }
        }
    }
};