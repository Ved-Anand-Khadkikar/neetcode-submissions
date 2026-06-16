class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lastSmaller=INT_MIN;
        int count=0;
        int longest=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]-1==lastSmaller){
                count++;
                lastSmaller=nums[i];
            }
            else if(nums[i]==lastSmaller){
                continue;
            }
            else if(nums[i]-1!=lastSmaller){
                count=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,count);
        }
        return longest;
    }
};
