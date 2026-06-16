class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        // dq--> 6(6) 
        // ans --> 2 2 4 4 6
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {
            while (dq.size() > 0 && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while (dq.size() > 0 && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
