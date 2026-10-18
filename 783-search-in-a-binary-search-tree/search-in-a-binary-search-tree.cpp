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
TreeNode* Solve(TreeNode*root, int val){
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->val == val){
        return root;
    }

    if(val < root->val){
        return Solve(root->left , val);
    }

    return Solve(root->right,val);
   
}
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

    return Solve(root , val);
        
    }
};