class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        sum(nums, ans, temp, idx, target);
        return ans;
    }
    void sum(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == nums.size()) {
            return;
        }
        if (target >= nums[idx]) {
            temp.push_back(nums[idx]);
            sum(nums, ans, temp, idx, target - nums[idx]);
            temp.pop_back();
        }
        sum(nums, ans, temp, idx + 1, target);
    }
};