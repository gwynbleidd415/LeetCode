/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *solution1(ListNode *head) {
        if(head == nullptr) return head;
        ListNode *fast{head}, *slow{head};
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        fast = head;
        while(fast != slow) {
            slow = slow->next, fast = fast->next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        return solution1(head);
    }
};
