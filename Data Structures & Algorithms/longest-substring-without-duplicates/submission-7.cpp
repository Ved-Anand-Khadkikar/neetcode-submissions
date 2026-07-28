class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int len = 0;
        int n = s.length();

        while (r < n) {
            mp[s[r]]++;

            if (mp.size() == r - l + 1) {
                maxLen = max(maxLen, r - l + 1);
            } else if (mp.size() < r - l + 1) {
                while (mp.size() < r - l + 1) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0) {
                        mp.erase(s[l]);
                    }
                    l++;
                }
                if (mp.size() == r - l + 1) {
                    maxLen = max(maxLen, r - l + 1);
                }
            }
            r++;
        }
        return maxLen;
    }
};
