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
    bool solution1(TreeNode* p, TreeNode* q) {
        if(p == nullptr) {
            if(q == nullptr) return true;
            return false;
        }
        if(q == nullptr) return false;
        if(p->val != q->val) return false;
        if(!solution1(p->left, q->left)) return false;
        return solution1(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solution1(p, q);
    }
};