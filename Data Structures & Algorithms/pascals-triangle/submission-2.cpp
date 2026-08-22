class Solution {
   public:
    vector<int> generateRows(int row) {
        vector<int> ans;
        ans.push_back(1);
        long long res = 1;
        for (int j = 1; j < row; j++) {
            res *= (row - j);
            res = res / j;
            ans.push_back(res);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector < vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = generateRows(i);
            ans.push_back(temp);
        }
        return ans;
    }
};