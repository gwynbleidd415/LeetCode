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
    TreeNode* solution1Helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int &pi) {
        if(is > ie) return nullptr;
        TreeNode *node = new TreeNode(postorder[pi]);
        int ii{ie};
        while(inorder[ii] != postorder[pi]) --ii;
        --pi;
        node->right = solution1Helper(inorder, postorder, ii+1, ie, pi);
        node->left = solution1Helper(inorder, postorder, is, ii-1, pi);
        return node;
    }
    TreeNode* solution1(vector<int>& inorder, vector<int>& postorder) {
        int pi = postorder.size() - 1;
        return solution1Helper(inorder, postorder, 0, pi, pi);
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solution1(inorder, postorder);
    }
};