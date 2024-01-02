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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *t1{head}, *t2{head->next}, *head2{t2};
        while(t2 && t2->next){
            t1->next = t2->next;
            t1 = t1->next;
            t2->next = t1->next;
            t2 = t2->next;
        }
        t1->next = head2;
        return head;
    }
};