class Solution {
   public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;
        while (s[i] == ' ' && i>=0) {
            i--;
        }
        while(s[i]!=' ' && i>=0){
            length++;
            i--;
        }
        return length;
    }
};