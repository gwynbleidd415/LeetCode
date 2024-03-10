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
        ListNode ans;
        ans.next = head;
        ListNode *tail{&ans}, *temp;
        int next;
        while(tail->next && tail->next->next) {
            if(tail->next->val != tail->next->next->val) {
                tail = tail->next;
                continue;
            }
            next = tail->next->val;
            temp = tail->next;
            while(temp && temp->val == next) {
                tail->next = temp->next;
                delete temp;
                temp = tail->next;
            }
        }
        return ans.next;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return solution1(head);
    }
};