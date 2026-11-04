class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubsets(nums, ans, 0, temp);
        return ans;
    }
    void generateSubsets(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int> temp) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        generateSubsets(nums, ans, idx + 1, temp);  // include
        temp.pop_back();
        generateSubsets(nums, ans, idx + 1, temp);  // exclude
    }
};
