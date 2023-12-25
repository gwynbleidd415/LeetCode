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
    void updateCarryTail(ListNode **tail, int &carry, int summ){
        carry = summ / 10;
        (*tail)->next = new ListNode(summ%10);
        *tail = (*tail)->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *tail = l3;
        int summ = 0, carry = 0;
        while(l1 && l2){
            summ = l1->val + l2->val + carry;
            updateCarryTail(&tail, carry, summ);
            l1 = l1->next, l2 = l2->next;
        }
        while(l1){
            summ = l1->val + carry;
            updateCarryTail(&tail, carry, summ);
            l1 = l1->next;
        }
        while(l2){
            summ = l2->val + carry;
            updateCarryTail(&tail, carry, summ);
            l2 = l2->next;
        }
        if(carry){
            tail->next = new ListNode(carry);
        }
        return l3->next;
    }
};