class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n);
        stack<int>nextSmallerElement;
        vector<int>pse(n);
        stack<int>previousSmallerElement;
        int maxArea=0;

        for(int i=0;i<n;i++){
            while(!previousSmallerElement.empty() && heights[previousSmallerElement.top()]>=heights[i]){
                previousSmallerElement.pop();
            }
            if(previousSmallerElement.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=previousSmallerElement.top();
            }
            previousSmallerElement.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!nextSmallerElement.empty() && heights[nextSmallerElement.top()]>=heights[i]){
                nextSmallerElement.pop();
            }
            if(nextSmallerElement.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=nextSmallerElement.top();
            }
            nextSmallerElement.push(i);
        }

        for(int i=0;i<n;i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
