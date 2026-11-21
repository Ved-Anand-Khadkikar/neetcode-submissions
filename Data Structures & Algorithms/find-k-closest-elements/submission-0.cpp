class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> ans;
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back({abs(x - arr[i]), i});
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < k; i++) {
            auto [diff, index] = ans[i];
            result.push_back(arr[index]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};