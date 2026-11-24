class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> bucket;
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]]++;
        }
        for (auto it : bucket) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while (!minHeap.empty()) {
            auto [freq, num] = minHeap.top();
            ans.push_back(num);
            minHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
