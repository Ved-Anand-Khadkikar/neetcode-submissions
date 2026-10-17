class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            int k = nums.size() - 1;
            int j = i + 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
// -4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4