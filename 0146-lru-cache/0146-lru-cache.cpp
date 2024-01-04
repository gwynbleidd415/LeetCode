class LRUCache {
private:
    queue<int> kq;
    unordered_map<int, int> umap, umapc;
    unordered_map<int, int>::iterator umitr;
    int capacity, keyCount;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->keyCount = 0;
    }
    
    int get(int key) {
        umitr = umap.find(key);
        if(umitr == umap.end()) return -1;
        kq.push(key), ++umapc[key];
        return umitr->second;
    }
    
    void put(int key, int value) {
        umitr = umap.find(key);
        umap[key] = value, ++umapc[key], kq.push(key);
        // if(umitr == umap.end()) ++keyCount;
        if(umitr == umap.end()) {
            if(keyCount < capacity) {
                ++keyCount;
                return;
            }
            while(true) {
                umitr = umapc.find(kq.front()), kq.pop();
                if (--(umitr->second) == 0) {
                    umap.erase(umitr->first);
                    umapc.erase(umitr);
                    break;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */