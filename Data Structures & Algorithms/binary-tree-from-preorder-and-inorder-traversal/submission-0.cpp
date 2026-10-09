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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) {
            return NULL;
        }
        int rootVal = preorder[idx];
        int foundIndex;
        for (int i = start; i <= end; i++) {
            if (rootVal == inorder[i]) {
                foundIndex = i;
                break;
            }
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, foundIndex - 1, idx);
        root->right = solve(preorder, inorder, foundIndex + 1, end, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int start = 0;
        int idx = 0;
        int end = n - 1;
        return solve(preorder, inorder, start, end, idx);
    }
};
