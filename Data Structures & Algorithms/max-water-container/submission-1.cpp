class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area=INT_MIN;
        int length;
        int breadth;
        for(int i=0;i<heights.size();i++){
            int area=0;
            // length=0;
            // breadth=0;
            for(int j=i+1;j<heights.size();j++){
                if(heights[i]<heights[j]){
                    length=heights[i];
                }
                else{
                    length=heights[j];
                }
                breadth=j-i;
                area=length*breadth;
                max_area=max(area,max_area);
            }
        }
        return max_area;
    }
};
