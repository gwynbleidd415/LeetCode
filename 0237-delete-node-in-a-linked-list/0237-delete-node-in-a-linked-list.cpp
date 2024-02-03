/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void solution1(ListNode* node) {
        while(node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
        delete node->next;
    }
    void solution2(ListNode* node) {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
public:
    void deleteNode(ListNode* node) {
        // solution1(node);
        solution2(node);
    }
};