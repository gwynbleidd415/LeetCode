/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node *solution1(Node *root) {
        if(root == nullptr) return root;
        queue<Node *> qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            while(--size) {
                Node *front = qu.front();
                qu.pop();
                front->next = qu.front();
                if(front->left) qu.push(front->left);
                if(front->right) qu.push(front->right);
            }
            Node *front = qu.front(); qu.pop();
            if(front->left) qu.push(front->left);
            if(front->right) qu.push(front->right);
        }
        return root;
    }
    Node *solution2(Node *root) {
        if(root == nullptr) return root;
        Node *node{root};
        while(node) {
            Node dummy(0);
            for(Node *nextLevel{&dummy}; node; node = node->next) {
                if(node->left) {
                    nextLevel->next = node->left;
                    nextLevel = nextLevel->next;
                } if(node->right) {
                    nextLevel->next = node->right;
                    nextLevel = nextLevel->next;
                }
            }
            node = dummy.next;
        }
        return root;
    }
public:
    Node* connect(Node* root) {
        // return solution1(root);
        return solution2(root);
    }
};