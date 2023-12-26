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
        // ListNode *tail = head->next;
        // int size = 1;
        // while(tail){
        //     tail = tail->next;
        //     ++size;
        // }
        // tail = head;
        // int toRem = size - n - 1;
        // if(toRem == -1){
        //     head = head->next;
        //     delete tail;
        //     return head;
        // }
        // while(toRem){
        //     tail = tail->next;
        //     --toRem;
        // }
        // ListNode *temp = tail->next;
        // tail->next = temp->next;
        // delete temp;
        // return head;

        // vector<ListNode *> arr{head};
        // ListNode *tail = head->next;
        // while(tail){
        //     arr.push_back(tail);
        //     tail = tail->next;
        // }
        // int toRem = arr.size() - n;
        // // cout << arr.size() << n << toRem << '\n';
        // if(toRem == 0){
        //     head = head->next;
        // } else {
        //     arr[toRem-1]->next = arr[toRem]->next;
        // }
        // delete arr[toRem];
        // return head;

        queue<ListNode *> qu;
        qu.push(head);
        ListNode *temp = head->next;
        while(temp){
            if(qu.size() == n+1) qu.pop();
            qu.push(temp);
            temp = temp->next;
        }
        if(qu.size() == n) {
            head = head->next;
        } else {
            temp = qu.front();
            qu.pop();
            temp->next = qu.front()->next;
        }
        delete qu.front();
        return head;
    }
};