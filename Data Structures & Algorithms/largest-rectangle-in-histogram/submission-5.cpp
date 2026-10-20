class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> previousSmallerElement;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!previousSmallerElement.empty() &&
                   heights[previousSmallerElement.top()] >= heights[i]) {
                int nse = i;
                int height = heights[previousSmallerElement.top()];
                previousSmallerElement.pop();
                int pse = previousSmallerElement.empty() ? -1 : previousSmallerElement.top();
                maxArea = max(maxArea, height * (nse - pse - 1));
            }
            previousSmallerElement.push(i);
        }
        while (!previousSmallerElement.empty()) {
            int nse = heights.size();
            int height = heights[previousSmallerElement.top()];
            previousSmallerElement.pop();
            int pse = previousSmallerElement.empty() ? -1 : previousSmallerElement.top();
            maxArea = max(maxArea, height * (nse - pse - 1));
        }
        return maxArea;
    }
};
