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
    ListNode* merge(ListNode *head1, ListNode *head2) {
        ListNode ans(0);
        ListNode *head3{&ans};

        while(head1 && head2) {
            if(head1->val < head2->val) head3->next = head1, head1 = head1->next;
            else head3->next = head2, head2 = head2->next;
            head3 = head3->next;
        }
        while(head1) {
            head3->next = head1, head1 = head1->next, head3 = head3->next;
        }
        while(head2) {
            head3->next = head2, head2 = head2->next, head3 = head3->next;
        }
        head3->next = nullptr;

        return ans.next;
    }
    ListNode* mergeSort(ListNode *head, ListNode *tail) {
        if(head == tail) return nullptr;
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }

        ListNode *slow, *fast;
        slow = fast = head;
        while(fast!=tail && fast->next!=tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *left = mergeSort(head, slow);
        ListNode *right = mergeSort(slow, tail);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }
};