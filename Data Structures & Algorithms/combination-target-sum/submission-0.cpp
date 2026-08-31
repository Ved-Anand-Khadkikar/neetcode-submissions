class Solution {
   public:
    void cSum(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> temp, int target) {
        if (i > nums.size() - 1) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[i] <= target) {
            temp.push_back(nums[i]);
            cSum(i, nums, ans, temp, target - nums[i]);
            temp.pop_back();
        }
        cSum(i + 1, nums, ans, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        cSum(0, nums, ans, temp, target);
        return ans;
    }
};
