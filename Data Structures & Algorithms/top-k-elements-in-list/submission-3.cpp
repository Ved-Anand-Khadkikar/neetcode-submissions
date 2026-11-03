class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& it : freq) {
            bucket[it.second].push_back(it.first);
        }
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (bucket[i].empty()) {
                continue;
            }
            while (!bucket[i].size() == 0 && k > 0) {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            if (k < 0) {
                break;
            }
        }
        return ans;
    }
};
