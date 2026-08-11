class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxLen = 1;

        while (r < n - 1) {
            if (nums[r] + 1 == nums[r + 1]) {
                maxLen = max(maxLen, r - l + 2);
            } else if (nums[r] == nums[r + 1]) {
                l++;
            } else {
                l = r + 1;
            }
            r++;
        }
        return (n == 0) ? 0 : maxLen;
    }
};
