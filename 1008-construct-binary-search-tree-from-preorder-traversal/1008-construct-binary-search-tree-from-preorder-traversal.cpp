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
    TreeNode* solution1Helper(vector<int>& preorder, int l, int r) {
        TreeNode *node = new TreeNode(preorder[l]);
        int m{l+1};
        while(m<=r && preorder[m] < preorder[l]) ++m;
        if(m > l+1) node->left = solution1Helper(preorder, l+1, m-1);
        if(m<=r) node->right = solution1Helper(preorder, m, r);
        return node;
    }
    TreeNode* solution1(vector<int>& preorder) {
        return solution1Helper(preorder, 0, preorder.size()-1);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solution1(preorder);
    }
};