class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int> pge(n);
        pge[0] = height[0];
        for (int i = 1; i < n; i++) {
            pge[i] = max(height[i], pge[i - 1]);
        }

        vector<int> nge(n);
        nge[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            nge[i] = max(height[i], nge[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            total += min(pge[i], nge[i]) - height[i];
        }
        return total;
    }
};
