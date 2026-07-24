class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int len = 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;

        while (r < n) {
            if (mp.find(s[r]) != mp.end()) {
                if (mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxLen = max(maxLen, len);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
