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
    ListNode* solution1(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        ListNode *node = new ListNode(0, head);
        ListNode *start{node}, *prev{node}, *curr{head};
        while(curr) {
            if(curr->val >= x) {
                prev = curr;
                curr = curr->next;
                continue;
            }
            if(prev == start) {
                prev = start = curr;
                curr = curr->next;
                continue;
            }
            prev->next = curr->next;
            curr->next = start->next;
            start->next = curr;
            start = start->next;
            curr = prev->next;
        }
        return node->next;
    }
    ListNode* solution2(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        ListNode less, eqgr;
        ListNode *lessi{&less}, *eqgri{&eqgr};
        while(head) {
            if(head->val < x) {
                lessi->next = head;
                while(head->next && head->next->val < x) head = head->next;
                lessi = head;
            } else {
                eqgri->next = head;
                while(head->next && head->next->val >= x) head = head->next;
                eqgri = head;
            }
            head = head->next;
        }
        eqgri->next = nullptr;
        lessi->next = eqgr.next;
        return less.next;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        // return solution1(head, x);
        return solution2(head, x);
    }
};