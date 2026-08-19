class Solution {
   public:
    void reverse(vector<int>& matrix) {
        int j = matrix.size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (j >= i) {
                int temp = matrix[j];
                matrix[j] = matrix[i];
                matrix[i] = temp;
            }
            j--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i]);
        }
    }
};
