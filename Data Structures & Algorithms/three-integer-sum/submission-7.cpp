class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        for (auto& p : st) {
            ans.push_back(p);
        }
        return ans;
    }
};
