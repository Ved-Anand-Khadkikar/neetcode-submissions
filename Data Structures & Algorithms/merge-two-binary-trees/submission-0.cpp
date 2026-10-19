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
    TreeNode* solve(TreeNode* copyRoot1, TreeNode* root2) {
        if (copyRoot1 != NULL && root2 != NULL) {
            copyRoot1->val += root2->val;
        } else if (copyRoot1 != NULL && root2 == NULL) {
            return copyRoot1;
        } else if (copyRoot1 == NULL && root2 != NULL) {
            return root2;
        } else {
            return root2;
        }
        copyRoot1->left = solve(copyRoot1->left, root2->left);
        copyRoot1->right = solve(copyRoot1->right, root2->right);
        return copyRoot1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* copyRoot1 = root1;
        return solve(copyRoot1, root2);
    }
};