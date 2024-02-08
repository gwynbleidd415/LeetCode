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
    Node* solution2(Node* head) {
        if(head == nullptr) return nullptr;
        Node *iter{head}, *newNode;
        while(iter) {
            newNode = new Node(iter->val);
            newNode->next = iter->next;
            iter->next = newNode;
            iter = iter->next->next;
        }
        iter = head;
        while(iter) {
            if(iter->random) iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        iter = head;
        Node newHead(0), *newIter{&newHead};
        while(iter) {
            newIter->next = iter->next;
            iter->next = iter->next->next;
            iter = iter->next;
            newIter = newIter->next;
        }
        return newHead.next;
    }
public:
    Node* copyRandomList(Node* head) {
        // return solution1(head);
        return solution2(head);
    }
};
