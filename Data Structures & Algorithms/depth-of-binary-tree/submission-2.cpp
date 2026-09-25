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
    int maxHeight(TreeNode* node, int& maxH) {
        if (node == NULL) {
            return 0;
        }
        int leftH = maxHeight(node->left, maxH);
        int rightH = maxHeight(node->right, maxH);
        maxH = max(maxH, max(leftH, rightH) + 1);
        return max(leftH, rightH) + 1;
    }

    int maxDepth(TreeNode* root) {
        int maxH = 0;
        maxHeight(root, maxH);
        return maxH;
    }
};
