class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0,nse,pse,area;
        int element;
        stack<int>st;
        //Previous Smaller Element
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                element=st.top();
                st.pop();
                nse=i;
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top();
                }
                area=heights[element]*(nse-pse-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            element=st.top();
            st.pop();
            pse=(st.empty())?-1:st.top();
            area=heights[element]*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
