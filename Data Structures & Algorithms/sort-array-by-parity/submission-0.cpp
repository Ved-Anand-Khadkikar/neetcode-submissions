class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd=i;
                break;
            }
        }
        if(odd==-1){
            return nums;
        }
        else{
            for(int i=odd+1;i<nums.size();i++){
                if(nums[i]%2==0){
                    swap(nums[odd],nums[i]);
                    odd++;
                }
            }
        }
        return nums;
    }
};