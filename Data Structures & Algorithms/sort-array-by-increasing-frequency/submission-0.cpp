class Solution {
   public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<vector<int>> bucket(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            bucket[it.second].push_back(it.first);
            if (bucket[it.second].size() > 1) {
                sort(bucket[it.second].begin(), bucket[it.second].end());
            }
        }
        for (int i = 0; i < bucket.size(); i++) {
            for (int j = bucket[i].size() - 1; j >= 0; j--) {
                for (int k = 0; k < i; k++) {
                    ans.push_back(bucket[i][j]);
                }
            }
        }
        return ans;
    }
};