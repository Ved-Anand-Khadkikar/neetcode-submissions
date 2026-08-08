class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int cnt = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};