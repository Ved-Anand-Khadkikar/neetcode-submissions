class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            // count = 0;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
                if(count==1){
                    return true;
                }
            }
        }
        return false;
    }
};