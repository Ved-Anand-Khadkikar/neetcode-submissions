class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        int l=0,r=0,minLen=INT_MAX,stIndex=-1,cnt=0;
        vector<int>hash(256,0);
        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }
        while(r<m){
            if(hash[s[r]]>0){
                cnt++; 
            }
            hash[s[r]]--;
            while(cnt==n){
                int len=r-l+1;
                if(len<minLen){
                    minLen=len;
                    stIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return stIndex==-1?"":s.substr(stIndex,minLen);
    }
};
