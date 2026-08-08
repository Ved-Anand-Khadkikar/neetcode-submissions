class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.length();
        int maxLen = INT_MIN;
        int maxFreq = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int changes = (r - l + 1) - maxFreq;
            if (changes <= k) {
                maxLen = max(maxLen, r - l + 1);
            } else {
                if (changes > k) {
                    mp[s[l]]--;
                    maxFreq = 0;
                    l++;
                    changes = (r - l + 1) - maxFreq;
                }
                if (changes <= k) {
                    maxLen = max(maxLen, r - l + 1);
                }
            }
            r++;
        }
        return maxLen;
    }
};
