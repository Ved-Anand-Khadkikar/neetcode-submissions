class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        vector<int> ans = {first, last};
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (first == -1 && last == -1) {
                    first = i;
                    last = i;
                } else {
                    last = i;
                    // break;
                }
            }
        }
        return {first, last};
    }
};