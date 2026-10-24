/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
int findposition(vector<int>& inorder, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postIndex,
                int size, int inorderStart, int inorderEnd) {
    // base case
    if (postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }
    // Create root from postorder
    int element = postorder[postIndex];
    postIndex--;
    TreeNode* root = new TreeNode(element);

    // Find root position in inorder
    int pos = findposition(inorder, size, element);

    // Build right subtree first
    root->right = solve(inorder, postorder, postIndex, size, pos + 1, inorderEnd);
    // Build left subtree
    root->left = solve(inorder, postorder, postIndex, size, inorderStart, pos - 1);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = postorder.size() - 1;
        return solve(inorder, postorder, postIndex, size, 0, size - 1);
    }
};