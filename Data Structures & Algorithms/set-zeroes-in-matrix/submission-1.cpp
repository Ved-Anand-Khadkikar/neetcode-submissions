class Solution {
   public:
    void markRow(vector<vector<int>>& matrix, int row, int m) {
        for (int col = 0; col < m; col++) {
            if (matrix[row][col] != 0) {
                matrix[row][col] = -1;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int col, int n) {
        for (int row = 0; row < n; row++) {
            if (matrix[row][col] != 0) {
                matrix[row][col] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, i, m);
                    markCol(matrix, j, n);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
