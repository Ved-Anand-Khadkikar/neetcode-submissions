class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n);
        vector<int> subMax(n);
        int total = 0;
        preMax[0] = height[0];
        subMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            subMax[i] = max(subMax[i + 1], height[i]);
        }
        for (int i = 0; i < n; i++) {
            if (height[i] < preMax[i] && height[i] < subMax[i]) {
                total += min(preMax[i], subMax[i]) - height[i];
            }
        }
        return total;
    }
};
