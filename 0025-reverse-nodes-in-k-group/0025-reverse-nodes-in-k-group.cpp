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
    ListNode* solution1(ListNode* head, const int k) {
        ListNode *next, *curr{head}, *prev{nullptr}, *ihead, *iprev{nullptr}, *nhead{nullptr};
        int kc{k};
        int cl{0};
        ListNode *temp{head};
        while(temp) temp = temp->next, ++cl;
        while(cl>=k) {
            ihead = curr;
            for(kc = 0;kc<k && curr != nullptr;++kc) {
                next = curr->next;
                curr->next = prev;
                prev = curr, curr = next;
            }
            cl -= k;
            if(nhead == nullptr) nhead = prev;
            if(iprev) iprev->next = prev;
            ihead->next = curr;
            iprev = ihead;
        }
        return nhead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solution1(head, k);
    }
};