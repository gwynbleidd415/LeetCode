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
    // void inorderTraversalHelper(TreeNode *root, vector<int> &ans){
    //     if(root == nullptr) return;
    //     inorderTraversalHelper(root->left, ans);
    //     ans.push_back(root->val);
    //     inorderTraversalHelper(root->right, ans);
    // }
    void inorderTraversalHelperStack(TreeNode *root, vector<int> &ans){
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorderTraversalHelper(root, ans);
        inorderTraversalHelperStack(root, ans);
        return ans;
    }
};