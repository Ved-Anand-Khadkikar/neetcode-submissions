class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>m;
            for(int j=i+1;j<n;j++){
                int k=-(nums[i]+nums[j]);
                if(m.find(k)!=m.end()){
                    vector<int>temp={k,nums[i],nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                m[nums[j]];
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
