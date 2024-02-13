/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* solution1Helper(Node *node, unordered_map<Node *, Node *> &umap) {
        if(node == nullptr) return nullptr;
        if(umap.find(node) != umap.end()) return umap[node];
        Node *newNode = new Node(node->val);
        umap[node] = newNode;
        for(Node *ch: node->neighbors) {
            newNode->neighbors.push_back(solution1Helper(ch, umap));
        }
        return newNode;
    }
    Node* solution1(Node *node) {
        unordered_map<Node *, Node *> umap;
        return solution1Helper(node, umap);
    }
public:
    Node* cloneGraph(Node* node) {
        return solution1(node);
    }
};