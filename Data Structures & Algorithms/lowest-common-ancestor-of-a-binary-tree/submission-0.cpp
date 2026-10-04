/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    bool pathsP(TreeNode* node, TreeNode* target, vector<TreeNode*>& pathP) {
        if (node == NULL) {
            return false;
        }
        pathP.push_back(node);
        if (node == target) {
            return true;
        }
        if (pathsP(node->left, target, pathP) || pathsP(node->right, target, pathP)) {
            return true;
        }
        pathP.pop_back();
        return false;
    }
    bool pathsQ(TreeNode* node, TreeNode* target, vector<TreeNode*>& pathQ) {
        if (node == NULL) {
            return false;
        }
        pathQ.push_back(node);
        if (node == target) {
            return true;
        }
        if (pathsQ(node->left, target, pathQ) || pathsQ(node->right, target, pathQ)) {
            return true;
        }
        pathQ.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        pathsP(root, p, pathP);
        pathsQ(root, q, pathQ);
        int size = pathP.size() <= pathQ.size() ? pathP.size() : pathQ.size();
        TreeNode* lca;

        for (int i = 0; i < size; i++) {
            if (pathP[i] == pathQ[i]) {
                lca = pathP[i];
            } else {
                break;
            }
        }
        return lca;
    }
};