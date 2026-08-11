class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lastSmall = nums[0];
        int n = nums.size();
        int longest = 1;
        int cnt = 1;

        if (n == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 == lastSmall) {
                cnt++;
            } else if (nums[i] == lastSmall) {
                continue;
            } else {
                cnt = 1;
            }
            lastSmall = nums[i];
            longest = max(longest, cnt);
        }
        return longest;
    }
};
