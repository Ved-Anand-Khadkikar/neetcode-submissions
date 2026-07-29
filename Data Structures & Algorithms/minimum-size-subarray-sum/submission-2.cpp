class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int sum = 0;

        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};