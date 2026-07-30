class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        if (t.length() > s.length()) {
            return "";
        }
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int cnt = 0;
        int stIndex = -1;

        while (r < s.length()) {
            if (mp[s[r]] > 0) {
                cnt++;
            }
            mp[s[r]]--;
            while (cnt == t.length()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    stIndex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return (stIndex == -1) ? "" : s.substr(stIndex, minLen);
    }
};
