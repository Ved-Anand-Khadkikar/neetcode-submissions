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
    int pathSum(TreeNode* node, int& maxSum) {
        if (node == NULL) {
            return 0;
        }
        int leftSum = pathSum(node->left, maxSum);
        int rightSum = pathSum(node->right, maxSum);
        int best_answer = leftSum + rightSum + node->val;
        int any_one_is_valid = max(leftSum, rightSum) + node->val;
        int root = node->val;
        maxSum = max({best_answer, any_one_is_valid, root, maxSum});
        return max(root, any_one_is_valid);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum == INT_MIN ? 0 : maxSum;
    }
};
