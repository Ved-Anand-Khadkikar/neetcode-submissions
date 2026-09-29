/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == NULL) {
            return ans;
        }
        bool flag = false;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            stack<int> st;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (flag) {
                    st.push(node->val);
                } else {
                    temp.push_back(node->val);
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            flag = !flag;
            while (!st.empty()) {
                temp.push_back(st.top());
                st.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};