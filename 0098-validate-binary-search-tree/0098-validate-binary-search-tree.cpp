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
    bool isValidBSTHelper(TreeNode *root, long long int lt, long long int gt){
        if(root == nullptr) return true;

        if(root->val >= lt || root->val <= gt) return false;

        return (isValidBSTHelper(root->left, root->val, gt) && isValidBSTHelper(root->right, lt, root->val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT64_MAX, INT64_MIN);
    }
};