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
    TreeNode* solution1Helper(vector<int>& preorder, vector<int>& inorder, int il, int ir, int &pi) {
        if(il > ir) return nullptr;
        int i{il};
        for(;i<=ir;++i) {
            if(inorder[i] == preorder[pi]) break;
        }
        TreeNode *node = new TreeNode(preorder[pi++]);
        node->left = solution1Helper(preorder, inorder, il, i-1, pi);
        node->right = solution1Helper(preorder, inorder, i+1, ir, pi);
        return node;
    }
private:
    TreeNode* solution1(vector<int>& preorder, vector<int>& inorder) {
        int pi{0};
        return solution1Helper(preorder, inorder, 0, inorder.size() - 1, pi);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solution1(preorder, inorder);
    }
};