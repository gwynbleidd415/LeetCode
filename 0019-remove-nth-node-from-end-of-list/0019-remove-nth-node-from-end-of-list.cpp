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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head->next;
        int size = 1;
        while(tail){
            tail = tail->next;
            ++size;
        }
        tail = head;
        int toRem = size - n - 1;
        if(toRem == -1){
            head = head->next;
            delete tail;
            return head;
        }
        while(toRem){
            tail = tail->next;
            --toRem;
        }
        ListNode *temp = tail->next;
        tail->next = temp->next;
        delete temp;
        return head;
    }
};