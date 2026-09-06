class Solution {
    void subset(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
                set<vector<int>>& st) {
        if (ind == nums.size()) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        subset(ind + 1, nums, ans, temp, st);
        temp.pop_back();
        subset(ind + 1, nums, ans, temp, st);
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        subset(0, nums, ans, temp, st);
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
