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
    int solution1Helper(TreeNode* root, bool &isHeightBalanced) {
        if(root == nullptr) return 0;
        int left = solution1Helper(root->left, isHeightBalanced);
        if(!isHeightBalanced) return left;
        int right = solution1Helper(root->right, isHeightBalanced);
        if(!isHeightBalanced) return right;
        if(abs(left-right) > 1) isHeightBalanced = false;
        return max(left, right) + 1;
    }
    bool solution1(TreeNode* root) {
        bool isHeightBalanced{true};
        solution1Helper(root, isHeightBalanced);
        return isHeightBalanced;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solution1(root);
    }
};