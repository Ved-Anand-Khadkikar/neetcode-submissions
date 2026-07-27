class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                int area = h * (nse - pse - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int h = heights[st.top()];
            st.pop();
            int pse = (st.empty()) ? -1 : st.top();
            int area = h * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
