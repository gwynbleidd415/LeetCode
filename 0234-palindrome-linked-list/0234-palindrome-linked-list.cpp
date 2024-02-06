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
    ListNode *reverse(ListNode *head) {
        ListNode *prev{nullptr}, *curr{head}, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }
    bool solution1(ListNode* head) {
        ListNode *slow{head}, *fast{head};
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        ListNode *itr1{reverse(slow)}, *itr2{head};
        while(itr1) {
            if(itr1->val != itr2->val) return false;
            itr1 = itr1->next, itr2 = itr2->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        return solution1(head);
    }
};