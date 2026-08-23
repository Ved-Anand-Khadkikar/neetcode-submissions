class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mp;
            for (int j = i + 1; j < nums.size(); j++) {
                int k = -(nums[i] + nums[j]);
                if (mp.find(k) != mp.end()) {
                    vector<int> temp = {nums[i], nums[j], k};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]++;
            }
        }
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
