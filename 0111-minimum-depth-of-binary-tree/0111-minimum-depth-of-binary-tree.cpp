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
    void solution1Helper(TreeNode *root, int depth, int &ans) {
        if(root->left == nullptr && root->right == nullptr) {
            ans = min(ans, depth);
            return;
        }
        if(root->left) solution1Helper(root->left, depth+1, ans);
        if(root->right) solution1Helper(root->right, depth+1, ans);
    }
    int solution1(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans{INT_MAX};
        solution1Helper(root, 1, ans);
        return ans;
    }
public:
    int minDepth(TreeNode* root) {
        return solution1(root);
    }
};