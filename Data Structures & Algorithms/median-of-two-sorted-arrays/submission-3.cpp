class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int i = 0;
        int j = 0;
        vector<int> nums3;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] >= nums2[j]) {
                nums3.push_back(nums2[j]);
                j++;
            } else {
                nums3.push_back(nums1[i]);
                i++;
            }
        }
        while (j < nums2.size()) {
            nums3.push_back(nums2[j]);
            j++;
        }
        while (i < nums1.size()) {
            nums3.push_back(nums1[i]);
            i++;
        }
        if (nums3.size() % 2 != 0) {
            ans = nums3[nums3.size() / 2];
        } else {
            int n = nums3.size() / 2;
            int num1 = nums3[n];
            int num2 = nums3[n - 1];
            ans = (num1 + num2) / 2.0;
        }
        return ans;
    }
};
// i 0 1 2 j 0 1