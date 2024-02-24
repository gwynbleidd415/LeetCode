class Trie {
    struct Node {
        bool isEnd;
        Node *children[26];
        Node() {
            isEnd = false;
            fill(children, children+26, nullptr);
        }
    };
    int getIndex(char ch) {
        return ch-'a';
    }
    Node *thead;
public:
    Trie() {
        thead = new Node();
    }
    
    void insert(string word) {
        Node *titr{thead};
        int index;
        for(char ch: word) {
            index = getIndex(ch);
            if(!titr->children[index]) titr->children[index] = new Node();
            titr = titr->children[index];
        }
        titr->isEnd = true;
    }
    
    bool search(string word) {
        Node *titr{thead};
        int index;
        for(char ch: word) {
            index = getIndex(ch);
            if(!titr->children[index]) return false;
            titr = titr->children[index];
        }
        return titr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *titr{thead};
        int index;
        for(char ch: prefix) {
            index = getIndex(ch);
            if(!titr->children[index]) return false;
            titr = titr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */