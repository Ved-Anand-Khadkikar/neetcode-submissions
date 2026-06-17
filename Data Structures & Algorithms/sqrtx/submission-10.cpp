class Solution {
   public:
    int mySqrt(int x) {
        int ans;
        for (int i = 0; i <= x; i++) {
            long long sq = 1LL * i * i;
            if (sq <= x) {
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
};