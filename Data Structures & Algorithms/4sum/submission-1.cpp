class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                unordered_set<long long> mp;
                for (int k = j + 1; k < nums.size(); k++) {
                    long long x = (long long)target - ((long long)nums[i] + nums[j] + nums[k]);
                    if (mp.find(x) != mp.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)x};
                        sort(temp.begin(), temp.end());
                        st1.insert(temp);
                    }
                    mp.insert(nums[k]);
                }
            }
        }
        for (auto it : st1) {
            ans.push_back(it);
        }
        return ans;
    }
};