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
    TreeNode* delNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > key) {
            root->left = delNode(root->left, key);
        } else if (root->val < key) {
            root->right = delNode(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* is = getInorderSuccessor(root->right);
                root->val = is->val;
                root->right = delNode(root->right, is->val);
            }
        }
        return root;
    }

    TreeNode* getInorderSuccessor(TreeNode* root) {
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return delNode(root, key);
    }
};