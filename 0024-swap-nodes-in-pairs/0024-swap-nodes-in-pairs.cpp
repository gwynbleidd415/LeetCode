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
    ListNode* solution1(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *citr{head}, *nnext, *prev, *nhead;
        nhead = citr->next;
        nnext = citr->next->next;
        citr->next->next = citr;
        prev = citr, citr = nnext;
        while(citr && citr->next) {
            prev->next = citr->next;
            nnext = citr->next->next;
            citr->next->next = citr;
            prev = citr, citr = nnext;
        }
        prev->next = citr;
        return nhead;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return solution1(head);
    }
};