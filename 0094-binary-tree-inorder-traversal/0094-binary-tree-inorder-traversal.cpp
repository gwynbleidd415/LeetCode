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
    void solution1Helper(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        solution1Helper(root->left, ans);
        ans.push_back(root->val);
        solution1Helper(root->right, ans);
    }
    vector<int> solution1(TreeNode* root) {
        vector<int> ans;
        solution1Helper(root, ans);
        return ans;
    }
    void solution2Helper(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        stack<TreeNode *> st;
        TreeNode *temp, *curr{root};
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            curr = temp->right;
        }
    }
    vector<int> solution2(TreeNode* root) {
        vector<int> ans;
        solution2Helper(root, ans);
        return ans;
    }
    vector<int> solution3(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr{root}, *prev;
        while(curr != nullptr) {
            if(curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;
                while(prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // return solution1(root);
        // return solution2(root);
        return solution3(root);
    }
};