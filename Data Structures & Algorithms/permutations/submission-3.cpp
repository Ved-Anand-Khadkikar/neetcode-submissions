class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> st;
        vector<int> temp;
        int idx = 0;
        solve(nums, ans, temp, st);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
               unordered_set<int>& st) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(nums, ans, temp, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
};