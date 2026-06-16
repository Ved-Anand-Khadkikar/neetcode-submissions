class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area=INT_MIN;
        int length;
        int breadth;
        int area;
        for(int i=0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
                length=min(heights[i],heights[j]);
                breadth=j-i;
                area=length*breadth;
                max_area=max(area,max_area);
            }
        }
        return max_area;
    }
};
