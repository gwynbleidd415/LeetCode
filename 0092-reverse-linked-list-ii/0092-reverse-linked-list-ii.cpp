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
private:
    ListNode* solution1(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode ansn(0, head);
        ListNode *inext{&ansn};
        right = right-left+1;
        --left;
        while(left) {
            --left;
            inext = inext->next;
        }
        ListNode *curr{inext->next}, *prev{nullptr}, *next;
        while(right) {
            next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
            --right;
        }
        inext->next->next = curr;
        inext->next = prev;
        return ansn.next;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return solution1(head, left, right);
    }
};