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
    void assignMLeftRight(TreeNode *root, int cPos, int &mLeft, int &mRight) {
        if(root == nullptr) return;
        mLeft = min(mLeft, cPos);
        mRight = max(mRight, cPos);
        assignMLeftRight(root->left, cPos-1, mLeft, mRight);
        assignMLeftRight(root->right, cPos+1, mLeft, mRight);
    }
    vector<vector<int>> solution1(TreeNode* root) {
        int mleft{0}, mright{0};
        assignMLeftRight(root, 0, mleft, mright);
        int sz = mright-mleft+1;
        vector<vector<int>> ans(sz);
        queue<pair<TreeNode *, int>> qu;
        qu.push({root, -mleft});
        vector<int> currSize(sz);
        pair<TreeNode *, int> front;
        while(!qu.empty()) {
            int size = qu.size();
            unordered_set<int> toSort;
            while(size) {
                front = qu.front(), qu.pop();
                ans[front.second].push_back(front.first->val);
                toSort.insert(front.second);
                if(front.first->left) qu.push({front.first->left, front.second-1});
                if(front.first->right) qu.push({front.first->right, front.second+1});
                --size;
            }
            for(int itr: toSort) {
                sort(ans[itr].begin() + currSize[itr], ans[itr].end());
                currSize[itr] = ans[itr].size();
            }
        }
        return ans;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return solution1(root);
    }
};