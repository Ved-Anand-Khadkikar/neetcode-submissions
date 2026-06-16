class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>cars(n);
        stack<double>st;
        for(int i=0;i<n;i++){
            cars[i]={position[i],speed[i]};
        }

        sort(cars.begin(),cars.end());

        for(int i=n-1;i>=0;i--){
            double time=(double)(target-cars[i].first)/cars[i].second;
            if(st.empty()){
                st.push(time);
            }
            if(!st.empty() && time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
