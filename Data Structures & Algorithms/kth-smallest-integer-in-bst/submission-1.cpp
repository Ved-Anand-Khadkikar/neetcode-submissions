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

    void solve(TreeNode*root,vector<int>&elements){
        if(root==NULL){
            return;
        }
        solve(root->left,elements);
        elements.push_back(root->val);
        solve(root->right,elements);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>elements;
        solve(root,elements);
        for(int i=0;i<k;i++){
            if(i==k-1){
                return elements[i];
            }
        }
        return 0;
    }
};
