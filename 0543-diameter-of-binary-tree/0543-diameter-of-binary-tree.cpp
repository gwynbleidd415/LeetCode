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
    int diameterOfBinaryTreeHelper(TreeNode* root, int &ans) {
        if(root == nullptr) return 0;
        int left = diameterOfBinaryTreeHelper(root->left, ans);
        int right = diameterOfBinaryTreeHelper(root->right, ans);
        ans = max(ans, left+right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans{0};
        diameterOfBinaryTreeHelper(root, ans);
        return ans;
    }
};