class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLen=1;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            int length;
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                if(m.find(s[j])==m.end()){
                    length=j-i+1;
                    maxLen=max(maxLen,length);
                    m[s[j]];
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};
