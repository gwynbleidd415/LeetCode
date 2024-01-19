/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p, q);
        TreeNode *temp = root;
        while(true) {
            if(temp == p || temp == q || (temp->val > p->val && temp->val < q->val)) return temp;
            if(temp->val < p->val) temp = temp->right;
            else temp = temp->left;
        }
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solution1(root, p, q);
    }
};