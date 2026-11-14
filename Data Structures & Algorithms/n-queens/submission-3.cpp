class Solution {
   public:
    vector<vector<string>> result;
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
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string> board, int row, int col, int n) {
        int j = col;
        if (row == 0) {
            return true;
        }
        // Upawrds
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
                ;
            }
        }
        col = j;
        // Right upward diagonal
        for (int i = row - 1; i >= 0; i--) {
            col++;
            if (col >= n) {
                break;
            } else if (board[i][col] == 'Q') {
                return false;
            }
        }
        col = j;
        // Left upward diagonal
        for (int i = row - 1; i >= 0; i--) {
            col--;
            if (col < 0) {
                break;
            }
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
