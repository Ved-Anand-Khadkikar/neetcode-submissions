class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        int ind = 0;
        subsets(nums, temp, ans, st, ind);
        return ans;
    }
    void subsets(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans,
                 set<vector<int>>& st, int ind = 0) {
        if (ind == nums.size()) {
            sort(temp.begin(), temp.end());
            if (st.find(temp) == st.end()) {
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }
        temp.push_back(nums[ind]);
        subsets(nums, temp, ans, st, ind + 1);
        temp.pop_back();
        subsets(nums, temp, ans, st, ind + 1);
    }
};
