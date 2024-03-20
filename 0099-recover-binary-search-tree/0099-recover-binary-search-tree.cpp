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
    TreeNode *solution1Helper(TreeNode *root, long lesser, long greater, bool &found) {
        if(root == nullptr) return nullptr;
        TreeNode *left = solution1Helper(root->left, lesser, root->val, found);
        if(found) return nullptr;
        if(left && left->val >= greater) return left;
        TreeNode *right = solution1Helper(root->right, root->val, greater, found);
        if(found) return nullptr;
        if(right && right->val <= lesser) return right;
        if(root->val <= lesser || root->val >= greater) return root;
        if(left && right) {
            swap(left->val, right->val), found = true;
            return nullptr;
        }
        if(left) {
            if(left->val >= root->val) {
                swap(left->val, root->val), found = true;
                return nullptr;
            }
            return left;
        }
        if(right) {
            if(right->val <= root->val) {
                swap(right->val, root->val), found = true;
                return nullptr;
            }
            return right;
        }
        return nullptr;
    }
    void solution1(TreeNode* root) {
        bool found{false};
        solution1Helper(root, INT64_MIN, INT64_MAX, found);
    }
    void solution2Helper(TreeNode *root, TreeNode **prev, TreeNode **less, TreeNode **more) {
        if(root == nullptr) return;
        solution2Helper(root->left, prev, less, more);
        if(*prev && (*prev)->val > root->val) {
            if(!*more) {
                *more = *prev;
            }
            *less = root;
        }
        *prev = root;
        solution2Helper(root->right, prev, less, more);
    }
    void solution2(TreeNode* root) {
        TreeNode *prev{nullptr}, *less{nullptr}, *more{nullptr};
        solution2Helper(root, &prev, &less, &more);
        swap(less->val, more->val);
    }
public:
    void recoverTree(TreeNode* root) {
        // solution1(root);
        solution2(root);
    }
};