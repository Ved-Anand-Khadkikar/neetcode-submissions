class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int minNum = INT_MAX;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[l] <= nums[m]) {
                minNum = min(nums[l], minNum);
                l = m + 1;
            } else {
                minNum = min(nums[m], minNum);
                h = m - 1;
            }
        }
        return minNum;
    }
};
