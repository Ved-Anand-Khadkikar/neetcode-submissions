class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }

    void function(string s, vector<vector<string>>& ans, int idx, vector<string>& temp) {
        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.length() ; i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (isPalindrome(sub)) {
                temp.push_back(sub);
                function(s, ans, i + 1, temp);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        function(s, ans, 0, temp);
        return ans;
    }
};
