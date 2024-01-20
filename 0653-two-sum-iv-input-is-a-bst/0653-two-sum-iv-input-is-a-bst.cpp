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
    bool isElementPresent1(TreeNode *root, int k) {
        if(root == nullptr) return false;
        if(root->val == k) return true;
        if(isElementPresent1(root->left,k)) return true;
        return isElementPresent1(root->right, k);
    }
    bool solution1Helper(TreeNode *root, TreeNode *curr, int k) {
        if(curr == nullptr) return false;
        int temp = k - curr->val;
        if(temp != curr->val && isElementPresent1(root, temp)) return true;
        if(solution1Helper(root, curr->left, k)) return true;
        return solution1Helper(root, curr->right, k); 
    }
    bool solution1(TreeNode* root, int k) {
        return solution1Helper(root, root, k);
    }
    bool solution2Helper(TreeNode *root, unordered_set<int> &uset, int k) {
        if(root == nullptr) return false;
        if(uset.find(k-root->val) != uset.end()) return true;
        uset.insert(root->val);
        if(solution2Helper(root->left, uset, k)) return true;
        return solution2Helper(root->right, uset, k); 
    }
    bool solution2(TreeNode* root, int k) {
        unordered_set<int> uset;
        return solution2Helper(root, uset, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        // return solution1(root, k);
        return solution2(root, k);
    }
};