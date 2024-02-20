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
    TreeNode* solution1Helper(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int m = (l+r)>>1;
        return new TreeNode(nums[m], solution1Helper(nums, l, m-1), solution1Helper(nums, m+1, r));
    }
    TreeNode* solution1(vector<int>& nums) {
        return solution1Helper(nums, 0, nums.size()-1);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solution1(nums);
    }
};