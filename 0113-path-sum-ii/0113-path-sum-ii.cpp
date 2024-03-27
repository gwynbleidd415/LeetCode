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
    void solution1Helper(TreeNode *root, int targetSum, vector<int> &curr, vector<vector<int>> &ans) {
        if(root == nullptr) return;
        curr.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        solution1Helper(root->left, targetSum-root->val, curr, ans);
        solution1Helper(root->right, targetSum-root->val, curr, ans);
        curr.pop_back();
    }
    vector<vector<int>> solution1(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> curr;
        solution1Helper(root, targetSum, curr, ans);
        return ans;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        return solution1(root, targetSum);
    }
};