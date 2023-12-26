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
    void list3Next(ListNode **list1, ListNode **list2){
        (*list1)->next = (*list2);
        (*list2) = (*list2)->next;
        (*list1) = (*list1)->next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* list3 = new ListNode();
        // ListNode* list3Head = list3;
        // while(list1 && list2){
        //     if(list1->val < list2->val){
        //         list3Next(&list3, &list1);
        //     } else {
        //         list3Next(&list3, &list2);
        //     }
        // }
        // while(list1){
        //     list3Next(&list3, &list1);
        // }
        // while(list2){
        //     list3Next(&list3, &list2);
        // }
        // return list3Head->next;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};