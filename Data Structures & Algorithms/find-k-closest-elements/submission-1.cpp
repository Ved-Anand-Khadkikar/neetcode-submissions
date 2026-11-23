class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            maxHeap.push({abs(x - arr[i]), arr[i]});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while (k > 0) {
            auto [diff, num] = maxHeap.top();
            maxHeap.pop();
            ans.push_back(num);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};