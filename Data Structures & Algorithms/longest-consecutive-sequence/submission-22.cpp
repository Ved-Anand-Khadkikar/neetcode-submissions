class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int lastSmall=INT_MIN;
        int longest=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastSmall){
                cnt++;
                lastSmall=nums[i];
            }
            // else if(nums[i]==lastSmall){
            //     continue;
            // }
            else if(nums[i]!=lastSmall){
                cnt=1;
                lastSmall=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};
//[2, 3, 4, 4, 5, 10, 20]
