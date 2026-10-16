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
    void solve(TreeNode* root , int targetSum , int currSum , vector<vector<int>> &ans, vector<int>path){
        // base case 
        if(root == NULL){
            return ; 
        }

        // Leaf Node 
        if(root ->left == NULL and root->right == NULL){
            path.push_back(root->val);
            currSum += root ->val;
            if(currSum == targetSum){
                ans.push_back(path);
            }
            return;
        }

        // include Current Node 
        path.push_back(root->val);
        currSum += root->val;

        solve(root->left,targetSum,currSum,ans,path);
        solve(root->right,targetSum,currSum,ans,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>ans;
        int sum =0;
        vector<int> temp;
        solve(root,targetSum , sum ,ans,temp);
        return ans;
    }
};