class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        solve(nums, ans, temp);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!checkNum(nums, temp, nums[i])) {
                temp.push_back(nums[i]);
                solve(nums, ans, temp);
                temp.pop_back();
            }
        }
    }
    bool checkNum(vector<int>& nums, vector<int>& temp, int num) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == num) {
                return true;
            }
        }
        return false;
    }
};
