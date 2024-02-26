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
    ListNode* solution2(ListNode* head) {
        ListNode *citr{head};
        while(citr && citr->next) {
            swap(citr->val, citr->next->val);
            citr = citr->next->next;
        }
        return head;
    }
    ListNode* solution3(ListNode* head) {
        ListNode *citr{head};
        ListNode *dummy = new ListNode();
        dummy->next = citr;
        ListNode *prev{dummy};
        while(citr && citr->next) {
            prev->next = citr->next;
            citr->next = citr->next->next;
            prev->next->next = citr;
            prev = citr, citr = citr->next;
        }
        return dummy->next;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        // return solution1(head);
        // return solution2(head);
        return solution3(head);
    }
};