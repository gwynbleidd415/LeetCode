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
class Solution {
    ListNode* solution1(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *prev{head}, *curr{head->next}, *next;
        head->next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return solution1(head);
    }
};