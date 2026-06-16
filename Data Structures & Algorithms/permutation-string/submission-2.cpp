class Solution {
public:

    bool isFreqSame(vector<int>s1,vector<int>s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int>s1Count(26,0);
        
        for(int i=0;i<s1.length();i++){
            s1Count[s1[i]-'a']++;
        }
        for(int j=0;j<s2.length();j++){
            vector<int>s2Count(26,0);
            int windIdx=0,idx=j;
            while(windIdx < s1.length() && idx < s2.length()){
                s2Count[s2[idx]-'a']++;
                windIdx++;
                idx++;
            }
            if(isFreqSame(s1Count,s2Count)){
                return true;
            }
        }
        return false;
    }
};
