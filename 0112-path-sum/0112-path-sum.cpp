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
private:
    bool solution1(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        return solution1(root->left, targetSum-root->val) || solution1(root->right, targetSum-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solution1(root, targetSum);
    }
};