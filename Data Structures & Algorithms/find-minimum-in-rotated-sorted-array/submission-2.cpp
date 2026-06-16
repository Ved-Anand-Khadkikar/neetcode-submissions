class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minNum = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[mid]) {
                minNum = min(minNum, nums[low]);
                low = mid + 1;
            } else {
                minNum = min(minNum, nums[mid]);
                high = mid - 1;
            }
        }
        return minNum;
    }
};
