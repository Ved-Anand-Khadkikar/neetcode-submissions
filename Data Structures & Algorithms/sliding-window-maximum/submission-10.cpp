class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int l = 0;
        int r = 0;
        deque<int> dq;

        while (r < n) {
            if (dq.empty()) {
                dq.push_back(r);
            } else {
                while (!dq.empty() && nums[dq.back()] < nums[r]) {
                    dq.pop_back();
                }
                dq.push_back(r);
            }
            if (r - l + 1 < k) {
                r++;
            } else if (r - l + 1 == k) {
                ans.push_back(nums[dq.front()]);
                l++;
                if (dq.front() < l) {
                    dq.pop_front();
                }
                r++;
            }
        }
        return ans;
    }
};
