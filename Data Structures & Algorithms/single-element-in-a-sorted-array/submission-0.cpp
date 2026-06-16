class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }
        for (const auto& p : m) {
            if (p.second == 1) {
                return p.first;
            }
        }
    }
};