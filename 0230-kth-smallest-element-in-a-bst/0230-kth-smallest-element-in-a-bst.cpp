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
    int solution1Helper(TreeNode* root, int k, int &citr) {
        if(root == nullptr) return -1;
        int left = solution1Helper(root->left, k, citr);
        if(citr == k) return left;
        ++citr;
        if(citr == k) return root->val;
        return solution1Helper(root->right, k, citr);
    }
    int solution1(TreeNode* root, int k) {
        int currItr{0};
        return solution1Helper(root, k, currItr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return solution1(root, k);
    }
};