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
    int solution1(TreeNode *root) {
        queue<pair<TreeNode *, long>> qu;
        qu.push({root, 1});
        long ans{1};
        pair<TreeNode *, long> front;
        while(!qu.empty()) {
            long start = qu.front().second;
            long end;
            int size = qu.size();
            while(size--) {
                front = qu.front(), qu.pop();
                end = front.second;
                if(front.first->left) {
                    qu.push({front.first->left, (front.second<<1) - 1});
                }
                if(front.first->right) {
                    qu.push({front.first->right, front.second<<1});
                }
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        return solution1(root);
    }
};