class Solution {
   public:
    bool isAlphaNum(char ch) {
        if (tolower(ch) >= 'a' && tolower(ch) <= 'z' || ch >= '0' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            while (!isAlphaNum(s[i])) {
                i++;
                // continue;
            }
            while (!isAlphaNum(s[j])) {
                j--;
                // continue;
            }
            if (i < j && tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
