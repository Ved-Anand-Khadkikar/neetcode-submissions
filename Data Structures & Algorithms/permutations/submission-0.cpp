class Solution {
   public:
    void function(vector<int>& nums, unordered_map<int, int>& mp, vector<int>& temp,
                  vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
                temp.push_back(nums[i]);
                function(nums, mp, temp, ans);
                temp.pop_back();
                mp.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> temp;
        function(nums, mp, temp, ans);
        return ans;
    }
};
