class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        solve(n, curr, ans);
        return ans;
    }
    void solve(int n, string& curr, vector<string>& ans) {
        if (curr.length() == 2 * n) {
            if (isValid(curr)) {
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(n, curr, ans);
        curr.pop_back();

        curr.push_back(')');
        solve(n, curr, ans);
        curr.pop_back();
    }
    bool isValid(string& curr) {
        stack<char> st;
        for (int i = 0; i < curr.length(); i++) {
            if (st.empty()) {
                st.push(curr[i]);
            } else if (curr[i] == '(') {
                st.push(curr[i]);
            } else if (st.top() == '(' && curr[i] == ')') {
                st.pop();
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
