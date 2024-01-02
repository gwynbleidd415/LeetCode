/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *travA{headA}, *travB{headB};
        int cnt{0};
        while(travA != travB){
            if(travA == nullptr) travA = headB;
            else travA = travA->next;
            if(travB == nullptr) travB = headA;
            else travB = travB->next;
        };
        return travA;
        // ListNode *travA{headA}, *travB{headB};
        // int cnt{0};
        // do{
        //     if(travA == travB) return travA;
        //     travA = travA->next, travB = travB->next;
        //     if(travA == nullptr){
        //         travA = headB;
        //         ++cnt;
        //     }
        //     if(travB == nullptr){
        //         travB = headA;
        //         ++cnt;
        //     }
        // }while(cnt<3);
        // return nullptr;
    }
};