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
    TreeNode* deleteRoot1(TreeNode *root) {
        TreeNode *temp;
        if(root->left == nullptr) {
            temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr) {
            temp = root->left;
            delete root;
            return temp;
        }
        TreeNode *par = root;
        temp = root->left;
        if(temp->right == nullptr) {
            temp->right = root->right;
            delete root;
            return temp;
        }
        while(temp->right->right) {
            temp = temp->right;
        }
        root->val = temp->right->val;
        temp->right = deleteRoot1(temp->right);
        return root;
    }
    TreeNode* solution1Helper(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key) return deleteRoot1(root);
        root->left = solution1Helper(root->left, key);
        root->right = solution1Helper(root->right, key);
        return root;
    }
    TreeNode* solution1(TreeNode* root, int key) {
        return solution1Helper(root, key);
    }
    TreeNode* deleteRoot2(TreeNode *root) {
        TreeNode *temp;
        if(root->left == nullptr) {
            temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr) {
            temp = root->left;
            delete root;
            return temp;
        }
        temp = root->left;
        while(temp->right) temp = temp->right;
        temp->right = root->right;
        temp = root->left;
        delete root;
        return temp;
    }
    TreeNode* solution2(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key) return deleteRoot2(root);
        TreeNode *temp = root, *par = nullptr;
        while(true) {
            if(key > temp->val) {
                if(temp->right == nullptr) break;
                if(temp->right->val == key) {
                    temp->right = deleteRoot2(temp->right);
                    break;
                } else temp = temp->right;
            } else {
                if(temp->left == nullptr) break;
                if(temp->left->val == key) {
                    temp->left = deleteRoot2(temp->left);
                    break;
                } else temp = temp->left;
            }
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // return solution1(root, key);
        return solution2(root, key);
    }
};