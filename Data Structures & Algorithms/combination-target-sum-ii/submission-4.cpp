class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        sum(candidates, ans, temp, target, 0);
        return ans;
    }
    void sum(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == nums.size()) {
            return;
        }
        if (target >= nums[idx]) {
            temp.push_back(nums[idx]);
            sum(nums, ans, temp, target - nums[idx], idx + 1);
            temp.pop_back();
            while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
                idx++;
            }
        }
        sum(nums, ans, temp, target, idx + 1);
    }
};
