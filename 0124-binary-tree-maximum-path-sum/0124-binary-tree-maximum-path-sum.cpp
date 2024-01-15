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
    int maxPathSumHelper(TreeNode* root, int &ans) {
        if(root == nullptr) return 0;
        int left = maxPathSumHelper(root->left, ans);
        int right = maxPathSumHelper(root->right, ans);
        ans = max(ans, left + right + root->val);
        return max(0, max(root->val + left, root->val + right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans{INT_MIN};
        maxPathSumHelper(root, ans);
        return ans;
    }
};