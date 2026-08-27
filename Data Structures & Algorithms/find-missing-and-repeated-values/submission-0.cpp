class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid[0].size()*grid[0].size();
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        long long S = 0;
        long long S2 = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                S += grid[i][j];
                S2 += (long long)(grid[i][j] * grid[i][j]);
            }
        }
        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 /= val1;
        long long x = (val1 + val2) / 2;
        long long y = val2 - x;
        return { (int)x, (int)y };
    }
};