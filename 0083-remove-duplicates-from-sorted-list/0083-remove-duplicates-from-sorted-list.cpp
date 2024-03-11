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
        ListNode *temp{head}, *temp1;
        while(temp) {
            while(temp->next && temp->next->val == temp->val) {
                temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
            }
            temp = temp->next;
        }
        return head;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return solution1(head);
    }
};