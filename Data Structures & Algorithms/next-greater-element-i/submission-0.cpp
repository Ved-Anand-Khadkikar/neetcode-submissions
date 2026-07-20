class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp;
        vector<int> nge(n, -1);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums2[j] > nums2[i]) {
                    nge[i] = nums2[j];
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = nge[i];
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};