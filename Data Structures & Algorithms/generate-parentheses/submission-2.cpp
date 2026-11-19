class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        int open = 0;
        int close = 0;
        solve(n, curr, ans, open, close);
        return ans;
    }
    void solve(int n, string& curr, vector<string>& ans, int open, int close) {
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            solve(n, curr, ans, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            solve(n, curr, ans, open, close + 1);
            curr.pop_back();
        }
    }
};
