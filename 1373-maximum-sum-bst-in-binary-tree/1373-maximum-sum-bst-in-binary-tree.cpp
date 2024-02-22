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
    pair<int, pair<int, int>> solution1Helper(TreeNode* root, int &ans) {
        if(root == nullptr) return {0, {INT_MAX, INT_MIN}};
        pair<int, pair<int, int>> left = solution1Helper(root->left, ans);
        pair<int, pair<int, int>> right = solution1Helper(root->right, ans);
        if(left.first == INT_MIN || right.first == INT_MIN || left.second.second >= root->val || right.second.first <= root->val) {
            return {INT_MIN, {0, 0}};
        };
        int currSum = left.first + right.first + root->val;
        ans = max(ans, currSum);
        int minn = left.second.second == INT_MIN ? root->val : left.second.first;
        int maxx = right.second.first == INT_MAX ? root->val : right.second.second;
        return {currSum, {minn, maxx}};
    }
    pair<int, pair<int, int>> solution1Helper2(TreeNode* root, int &ans) {
        if(root->left == nullptr && root->right == nullptr) {
            ans = max(ans, root->val);
            return {root->val, {root->val, root->val}};
        }
        pair<int, pair<int, int>> left;
        pair<int, pair<int, int>> right;
        if(root->left) {
            left = solution1Helper2(root->left, ans);
        } else {
            left = {0, {root->val, INT_MIN}};
        }
        if(root->right) {
            right = solution1Helper2(root->right, ans);
        } else {
            right = {0, {INT_MAX, root->val}};
        }
        if(left.second.second >= root->val || right.second.first <= root->val) {
            return {0, {INT_MIN, INT_MAX}};
        };
        int currSum = left.first + right.first + root->val;
        ans = max(ans, currSum);
        return {currSum, {left.second.first, right.second.second}};
    }
    int solution1(TreeNode* root) {
        int answer{0};
        // solution1Helper(root, answer);
        solution1Helper2(root, answer);
        return answer;
    }
public:
    int maxSumBST(TreeNode* root) {
        return solution1(root);
    }
};
