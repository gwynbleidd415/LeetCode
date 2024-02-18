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
    TreeNode *solution1Helper(TreeNode* root, TreeNode *par) {
        par->right = root;
        par->left = nullptr;
        if(root->left == nullptr) {
            if(root->right == nullptr) return root;
            return solution1Helper(root->right, root);
        }
        if(root->right == nullptr) {
            return solution1Helper(root->left, root);
        }
        TreeNode *right = root->right;
        return solution1Helper(right, solution1Helper(root->left, root));
    }
    void solution1(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode *par = new TreeNode();
        solution1Helper(root, par);
    }
public:
    void flatten(TreeNode* root) {
        solution1(root);
    }
};