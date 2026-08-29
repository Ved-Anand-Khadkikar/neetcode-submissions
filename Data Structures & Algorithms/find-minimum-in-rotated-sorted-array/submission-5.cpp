class Solution {
   public:
    int findMin(const vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minNum = INT_MAX;
        int index = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[mid]) {
                minNum=min(nums[low],minNum);
                low = mid + 1;
            } else {
                if (nums[mid] <= minNum) {
                    index=mid;
                    minNum = nums[mid];
                }
                high = mid - 1;
            }
        }
        return minNum;
    }
};