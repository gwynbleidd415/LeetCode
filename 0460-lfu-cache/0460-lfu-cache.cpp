class LFUCache {
    class MinHeap {
    private:
        int capacity, time;
        vector<int> arr;
        unordered_map<int, vector<int>> umap;
        unordered_map<int, vector<int>>::iterator uitr;

        void parChildSwap(int par, int child) {
            swap(umap[arr[par]][3], umap[arr[child]][3]);
            swap(arr[par], arr[child]);
        }
    public:
        MinHeap(int capacity) {
            this->time = 0;
            this->capacity = capacity + 1;
            arr.reserve(this->capacity);
            arr.push_back(-1);
        }
        void update(int par) {
            int n = arr.size();
            int ch1{par<<1}, ch2{ch1+1};
            while(true) {
                if(ch2 < n && umap[arr[par]][1] >= umap[arr[ch2]][1] && (umap[arr[ch2]][1] < umap[arr[ch1]][1] || umap[arr[ch2]][1] == umap[arr[ch1]][1] && umap[arr[ch2]][2] < umap[arr[ch1]][2])) {
                    parChildSwap(par, ch2);
                    par = ch2, ch1 = par<<1, ch2 = ch1+1;
                } else if(ch1 < n && umap[arr[par]][1] >= umap[arr[ch1]][1]) {
                    parChildSwap(par, ch1);
                    par = ch1, ch1 = par<<1, ch2 = ch1+1;
                } else break;
            }
        }
        void incrementCount (unordered_map<int, vector<int>>::iterator uitr) {
            uitr->second[2] = ++time;
            ++uitr->second[1];
            update(uitr->second[3]);
        }
        void insert(int key, int val) {
            uitr = umap.find(key);
            if(uitr != umap.end()) {
                uitr->second[0] = val;
                incrementCount(uitr);
                return;
            }
            if(arr.size() == capacity) {
                pop();
            }
            int ch = arr.size(), par = ch >> 1;
            arr.push_back(key);
            umap.insert({key, {val, 1, ++time, ch}});
            while(par>0 && umap[arr[par]][1] > umap[arr[ch]][1]) {
                parChildSwap(par, ch);
                ch = par, par = ch>>1;
            }
        }
        void pop() {
            parChildSwap(1,arr.size()-1);
            umap.erase(arr.back());
            arr.pop_back();
            update(1);
        }
        int get(int key) {
            uitr = umap.find(key);
            if(uitr == umap.end()) return -1;
            incrementCount(uitr);
            return uitr->second[0];
        }
    };
    MinHeap *mh;
public:
    LFUCache(int capacity) {
        mh = new MinHeap(capacity);
    }
    
    int get(int key) {
        return mh->get(key);
    }
    
    void put(int key, int value) {
        mh->insert(key, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */