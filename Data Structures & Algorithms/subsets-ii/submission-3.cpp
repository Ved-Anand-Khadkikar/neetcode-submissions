class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        subset(nums, ans, temp, i);
        return ans;
    }
    void subset(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int i) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(nums, ans, temp, i + 1);
        temp.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        subset(nums, ans, temp, i + 1);
    }
};
