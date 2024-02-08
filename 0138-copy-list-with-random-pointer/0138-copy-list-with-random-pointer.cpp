/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* solution1(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node *, Node *> umap;
        Node *temp{head}, *temp2;
        while(temp) {
            umap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            temp2 = umap[temp];
            temp2->next = umap[temp->next];
            temp2->random = umap[temp->random];
            temp = temp->next;
        }
        return umap[head];
    }
public:
    Node* copyRandomList(Node* head) {
        return solution1(head);
    }
};