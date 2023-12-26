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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode *mergedList = new ListNode();
        // ListNode *tail = mergedList;
        // int mi, n = lists.size();
        // while(true){
        //     mi = -1;
        //     for(int i = 0; i < n; ++i){
        //         if(!lists[i]) continue;
        //         if(mi == -1){
        //             mi = i;
        //             continue;
        //         }
        //         if(lists[i]->val < lists[mi]->val){
        //             mi = i;
        //         }
        //     }
        //     if(mi == -1) break;
        //     tail->next = lists[mi];
        //     tail = tail->next;
        //     lists[mi] = lists[mi]->next;
        // }
        // return mergedList->next;

        auto pqcomp = [](ListNode *a, ListNode *b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(pqcomp)> pq(pqcomp);
        for(ListNode* &list: lists){
            if(list) pq.push(list);
        }
        ListNode mergedList(0);
        ListNode *curr = &mergedList;
        ListNode *temp;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;
            temp = temp->next;
            if(temp) pq.push(temp);
        }
        return mergedList.next;
    }
};