class Solution {
public:
    int maxArea(vector<int>& heights) {
        int length;
        int breadth;
        int area;
        int max_area=INT_MIN;
        int i=0;
        int n=heights.size();
        int j=n-1;
        while(i<j){
            length=min(heights[i],heights[j]);
            breadth=j-i;
            area=length*breadth;
            max_area=max(area,max_area);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_area;
    }
};
