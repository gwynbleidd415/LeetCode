class Solution {
private:
    class Trie {
    private:
        int getIndex(char ch) {
            return ch-'a';
        }
    public:
        struct Node {
            vector<int> arr;
            vector<Node *> children;
            Node() {
                children.resize(26);
                for(int i{0};i<26;++i) children[i] = nullptr;
            }
        };
        vector<Node *> head;
        int wsize;
        Trie(int wsize) {
            head.resize(wsize);
            for(int i{0};i<wsize;++i) head[i] = new Node();
            this->wsize = wsize;
        }
        void insert(string &str, int ind) {
            Node *tail;
            int index, j;
            for(int i{0};i<wsize;++i) {
                tail = head[i];
                j = 0;
                for(;j<i;++j) {
                    if(tail->children[index = getIndex(str[j])] == nullptr) {
                        tail->children[index] = new Node();
                    }
                    tail = tail->children[index];
                }
                ++j;
                for(;j<wsize;++j) {
                    if(tail->children[index = getIndex(str[j])] == nullptr) {
                        tail->children[index] = new Node();
                    }
                    tail = tail->children[index];
                }
                tail->arr.push_back(ind);
            }
        }
        bool updateQueue(queue<int> &qu, unordered_set<int> &uset, string &str) {
            Node *tail;
            int index, j;
            for(int i{0};i<wsize;++i) {
                tail = head[i];
                j = 0;
                for(;j<i;++j) {
                    tail = tail->children[getIndex(str[j])];
                }
                ++j;
                for(;j<wsize;++j) {
                    tail = tail->children[getIndex(str[j])];
                }
                if(tail->arr[0] == 0) return true;
                for(int itr: tail->arr) {
                    if(uset.find(itr) == uset.end()) qu.push(itr), uset.insert(itr);
                }
            }
            // cout<<qu.size()<<' ';
            return false;
        }
    };
    int solution1(string &beginWord, string &endWord, vector<string>& wordList) {
        int n = beginWord.size();
        int endInd{-1}, begInd{-1}, si{0};
        for(int i{0};i<wordList.size();++i) {
            if(endInd == -1 && wordList[i] == endWord) {
                endInd = i;
            }
            if(begInd == -1 && wordList[i] == beginWord) {
                begInd = i;
            }
            if(endInd!=-1 && begInd!=-1) break;
        }
        // cout << endInd << ' ' << begInd << '\n';
        if(endInd == -1) return 0;
        if(begInd != -1) {
            swap(wordList[0], wordList[begInd]);
            if(endInd == 0) endInd = begInd;
            si = 1;
        }
        swap(wordList[si], wordList[endInd]);
        Trie trie(n);
        trie.insert(endWord, 0);
        trie.insert(beginWord, -1);
        for(int i{si+1};i<wordList.size();++i) trie.insert(wordList[i], i);
        queue<int> qu;
        unordered_set<int> uset;
        uset.insert(-1);
        if(trie.updateQueue(qu, uset, beginWord)) return 2;
        int front, ans{2}, sz;
        while(!qu.empty()) {
            sz = qu.size();
            ++ans;
            for(int i{0};i<sz;++i) {
                front = qu.front(), qu.pop();
                if(trie.updateQueue(qu, uset, wordList[front])) {
                    return ans;
                }
            }
        };
        return 0;
    }
    int solution2(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_set<string> uset;
        uset.insert(wordList.begin(), wordList.end());
        uset.erase(beginWord);
        if(uset.find(endWord) == uset.end()) return 0;
        queue<string> qu;
        qu.push(beginWord);
        int ans{1};
        char orig;
        string word;
        int sz;
        while(!qu.empty()) {
            ++ans;
            sz = qu.size();
            for(int ii{0};ii<sz;++ii){
                word = qu.front(), qu.pop();
                for(int i{0};i<n;++i) {
                    orig = word[i];
                    for(char ch='a';ch<='z';++ch) {
                        if(ch == orig) continue;
                        word[i] = ch;
                        if(word == endWord) return ans;
                        if(uset.find(word) != uset.end()) qu.push(word), uset.erase(word);
                    }
                    word[i] = orig;
                }
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // return solution1(beginWord, endWord, wordList);
        return solution2(beginWord, endWord, wordList);
    }
};
