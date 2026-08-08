class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                candidate = nums[i];
            }
            if (candidate == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return candidate;
    }
};