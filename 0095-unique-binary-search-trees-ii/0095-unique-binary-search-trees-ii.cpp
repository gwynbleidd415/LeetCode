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
    vector<TreeNode*> solution1Helper(int s, int e) {
        if(s > e) return {nullptr};
        if(s == e) {
            return {new TreeNode(s)};
        }
        vector<TreeNode *> ans;
        for(int i{s};i<=e;++i) {
            vector<TreeNode *> left, right;
            left = solution1Helper(s, i-1);
            right = solution1Helper(i+1, e);
            for(TreeNode *j: left) {
                for(TreeNode *k: right) {
                    ans.push_back(new TreeNode(i, j, k));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> solution1(int n) {
        return solution1Helper(1, n);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solution1(n);
    }
};