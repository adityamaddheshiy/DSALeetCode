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

    int Height(TreeNode* root){
        // base case 
        if(root == NULL){
            return 0;
        }
        int leftH = Height(root->left);
        int rightH = Height(root->right);
        return max(leftH, rightH)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 =(diff <=1);
        
        // recursion 
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns){
            return true;
        }else{
            return false;
        }
    }
};