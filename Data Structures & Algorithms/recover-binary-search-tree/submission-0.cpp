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
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        int index = 0;
        solve(root, inorder);
        sort(inorder.begin(), inorder.end());
        swap(root, inorder, index);
    }

    void solve(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    void swap(TreeNode* root, vector<int>& inorder, int& index) {
        if (root == NULL) {
            return;
        }
        swap(root->left, inorder, index);
        if (root->val == inorder[index]) {
            index++;
        } else {
            root->val = inorder[index];
            index++;
        }
        swap(root->right, inorder, index);
    }
};