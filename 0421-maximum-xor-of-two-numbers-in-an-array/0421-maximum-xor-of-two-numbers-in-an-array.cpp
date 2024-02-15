class Solution {
private:
    class Trie {
        private:
            struct Node {
                Node *children[2];
                Node() {
                    children[0] = children[1] = nullptr;
                }
            };
            Node *thead;
            int getIndex(char ch) {
                return ch - '0';
            }
            string getBinaryRepresentation(int num) {
                string str{""};
                for(int i{1<<30};i>0;i>>=1) {
                    if(i&num) str.push_back('1');
                    else str.push_back('0');
                }
                return str;
            }
        public:
            Trie() {
                thead = new Node();
            }
            void insert(int num) {
                string str = getBinaryRepresentation(num);
                Node *iter = thead;
                int index;
                for(char ch: str) {
                    index = getIndex(ch);
                    if(iter->children[index] == nullptr) {
                        iter->children[index] = new Node();
                    }
                    iter = iter->children[index];
                }
            }
            int getMaxXOR(int num) {
                string str = getBinaryRepresentation(num);
                Node *iter = thead;
                int ans{0};
                int index;
                for(int bi{1<<30}, i{0};bi>0;bi>>=1, ++i) {
                    index = !getIndex(str[i]);
                    if(iter->children[index]) {
                        ans = ans | bi;
                        iter = iter->children[index];
                    } else iter = iter->children[!index];
                }
                return ans;
            }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int num: nums) trie.insert(num);
        int ans{0};
        for(int num: nums) ans = max(ans, trie.getMaxXOR(num));
        return ans;
    }
};