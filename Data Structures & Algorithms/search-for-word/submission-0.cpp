class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (solve(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (idx == word.length()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size()) {
            return false;
        }

        if (board[row][col] != word[idx]) {
            return false;
        }

        char c = board[row][col];
        board[row][col] = '0';  // Mark visited

        bool found = solve(board, word, idx + 1, row - 1, col) ||  // Up
                     solve(board, word, idx + 1, row + 1, col) ||  // Down
                     solve(board, word, idx + 1, row, col - 1) ||  // Left
                     solve(board, word, idx + 1, row, col + 1);     // Right

        board[row][col] = c;  // Backtrack

        return found;
    }
};