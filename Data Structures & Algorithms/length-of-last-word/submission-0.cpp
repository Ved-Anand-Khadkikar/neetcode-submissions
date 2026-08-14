class Solution {
   public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        int len = 0;
        while (s[i] == ' ' && i >= 0) {
            i--;
        }
        while (s[i] != ' ' && i >= 0) {
            len++;
            i--;
        }
        return len;
    }
};