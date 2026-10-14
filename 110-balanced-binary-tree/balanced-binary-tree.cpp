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

        int leftheight =  Height(root-> left);
        int rightheight = Height(root ->right);
        int ans = 1 + max (leftheight ,rightheight);

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        // 1 Case 
        int leftHeight = Height(root ->left);
        int rightHeight = Height(root ->right);

        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff<=1);

        // recursion 
        bool  leftAns = isBalanced(root->left);
        bool  rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns){
            return true;
        }else {
            return false; 
        }
        
    }
};