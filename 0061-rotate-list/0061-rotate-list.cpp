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
    ListNode* solution1(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        int count{1};
        ListNode *temp, *tail{head};
        while(tail->next) tail = tail->next, ++count;
        k = k%count;
        if(k == 0) return head;
        temp = head;
        for(int i{count-k};i>1;--i) temp = temp->next;
        tail->next = head;
        ListNode *ans = temp->next;
        temp->next = nullptr;
        return ans;
    }
    ListNode* solution2(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        int count{1};
        ListNode *temp{head};
        while(temp->next) temp = temp->next, ++count;
        k = k%count;
        if(k == 0) return head;
        temp->next = head;
        for(int i{count-k};i>0;--i) temp = temp->next;
        ListNode *ans = temp->next;
        temp->next = nullptr;
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // return solution1(head, k);
        return solution2(head, k);
    }
};
