/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solution1Helper(ListNode* head, ListNode *tail) {
        if(head == tail) return nullptr;
        ListNode *slow{head}, *fast{head};
        while(fast!=tail && fast->next!=tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=tail) fast = fast->next;
        return new TreeNode(slow->val, solution1Helper(head, slow), solution1Helper(slow->next, fast));
    }
    TreeNode* solution1(ListNode* head) {
        return solution1Helper(head, nullptr);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return solution1(head);
    }
};