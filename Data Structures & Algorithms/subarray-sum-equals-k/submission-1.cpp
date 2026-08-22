class Solution {
   public:
    int cnt = 0;
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt++;
    }
};