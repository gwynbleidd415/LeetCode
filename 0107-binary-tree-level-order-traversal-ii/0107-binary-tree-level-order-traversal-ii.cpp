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
    vector<vector<int>> solution1(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode *> qu;
        qu.push(root);
        vector<vector<int>> ans;
        TreeNode *front;
        while(!qu.empty()) {
            int sz = qu.size();
            vector<int> currEls(sz);
            for(int i{0};i<sz;++i) {
                front = qu.front(), qu.pop();
                currEls[i] = front->val;
                if(front->left) qu.push(front->left);
                if(front->right) qu.push(front->right);
            }
            ans.push_back(currEls);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return solution1(root);
    }
};