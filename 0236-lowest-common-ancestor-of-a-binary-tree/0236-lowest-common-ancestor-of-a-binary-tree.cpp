/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void solution1DFS(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> &arr1, vector<TreeNode *> &arr2, bool &popAr1, bool &popAr2) {
        if(root == nullptr) return;
        if(popAr1) arr1.push_back(root);
        if(popAr2) arr2.push_back(root);
        if(root == p) {
            arr2.pop_back();
            popAr1 = false;
            return;
        }
        if(root == q) {
            arr1.pop_back();
            popAr2 = false;
            return;
        }
        solution1DFS(root->left, p, q, arr1, arr2, popAr1, popAr2);
        solution1DFS(root->right, p, q, arr1, arr2, popAr1, popAr2);
        if(popAr1) arr1.pop_back();
        if(popAr2) arr2.pop_back();
    }
    TreeNode* solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> arr1, arr2;
        bool popAr1{true}, popAr2{true};
        solution1DFS(root, p, q, arr1, arr2, popAr1, popAr2);
        if(arr1.size() == 0) return q;
        if(arr2.size() == 0) return p;
        for(int i{1};i<arr1.size();++i) {
            if(arr1[i]!=arr2[i]) return arr1[i-1];
        }
        return arr1.back();
    }
    TreeNode* solution2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode *left = solution2(root->left, p, q);
        TreeNode *right = solution2(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return solution1(root, p, q);
        return solution2(root, p, q);
    }
};