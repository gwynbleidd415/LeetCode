// class LRUCache {
// private:
//     queue<int> kq;
//     unordered_map<int, int> umap, umapc;
//     unordered_map<int, int>::iterator umitr;
//     int capacity, keyCount;
// public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         this->keyCount = 0;
//     }
    
//     int get(int key) {
//         umitr = umap.find(key);
//         if(umitr == umap.end()) return -1;
//         kq.push(key), ++umapc[key];
//         return umitr->second;
//     }
    
//     void put(int key, int value) {
//         umitr = umap.find(key);
//         umap[key] = value, ++umapc[key], kq.push(key);
//         if(umitr == umap.end()) {
//             if(keyCount < capacity) {
//                 ++keyCount;
//                 return;
//             }
//             while(true) {
//                 umitr = umapc.find(kq.front()), kq.pop();
//                 if (--(umitr->second) == 0) {
//                     umap.erase(umitr->first);
//                     umapc.erase(umitr);
//                     break;
//                 }
//             }
//         }
//     }
// };

class LRUCache {
private:

    class Node {
    public:
        int key, val;
        Node *next = nullptr, *prev = nullptr;
        Node(int key, int val): key(key), val(val) {} 
    };

    Node *head = nullptr, *tail = nullptr;
    unordered_map<int, Node *> umap;
    unordered_map<int, Node *>::iterator umitr;
    int capacity;

    void addNode(int key, int val) {
        Node *node = new Node(key, val);
        if(tail) {
            node->prev = tail;
            tail->next = node;
            tail = node;
        } else {
            head = tail = node;
        }
        umap[key] = node;
    }
    void deleteNode() {
        Node *node{head};
        if(head->next) head = head->next, head->prev = nullptr;
        else head = tail = nullptr;
        umitr = umap.find(node->key);
        // delete node;
        umap.erase(umitr);
    }
    void moveNodeToBack(Node *node) {
        if(node->next) node->next->prev = node->prev;
        else return;
        if(node->prev) node->prev->next = node->next;
        else head = node->next;
        node->prev = tail, tail->next = node, node->next = nullptr;
    }
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        umitr = umap.find(key);
        if(umitr == umap.end()) return -1;
        moveNodeToBack(umitr->second);
        return umitr->second->val;
    }
    
    void put(int key, int value) {
        umitr = umap.find(key);
        if(umitr == umap.end()) {
            if(umap.size() == capacity) deleteNode();
            addNode(key, value);
            return;
        } else {
            umitr->second->val = value;
            moveNodeToBack(umitr->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */