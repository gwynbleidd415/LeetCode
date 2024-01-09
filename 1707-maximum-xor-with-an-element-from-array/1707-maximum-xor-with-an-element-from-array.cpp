class Solution {
private:
    struct TrieNode {
        TrieNode *arr[2];
        TrieNode() {
            arr[0] = arr[1] = nullptr;
        }
    };
    int maximizeXorMaxx(TrieNode *trie, int xr, int curi) {
        if(curi == 0) return 0;
        bool ii = (xr&curi) == 0;
        if(trie->arr[ii]) return curi^maximizeXorMaxx(trie->arr[ii], xr, curi>>1);
        return maximizeXorMaxx(trie->arr[!ii], xr, curi>>1);
    }
    int maximizeXor(TrieNode *trie, int xr, int mx, int curi) {
        if(trie == nullptr) return -1;
        if(curi == 0) return 0;
        bool ind = (mx&curi) != 0;
        if(ind) {
            int ans1 = maximizeXor(trie->arr[1], xr, mx, curi>>1);
            int ans2 = trie->arr[0] ? maximizeXorMaxx(trie->arr[0], xr, curi>>1) : -1;
            if(ans1 == -1) {
                if(ans2 == -1) return -1;
                return (xr&curi)^ans2;
            }
            if(ans2 == -1) return (xr&curi)^curi^ans1;
            return max((xr&curi)^curi^ans1, (xr&curi)^ans2);
        } else {
            int ans = maximizeXor(trie->arr[0], xr, mx, curi>>1);
            if(ans!=-1) return (xr&curi)^ans;
            else return -1;
        }
    }
    vector<int> maximizeXorTrie(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode *head = new TrieNode(), *temp;
        int MAXI = 1<<30, curi;
        int index;
        for(int i{0};i<nums.size();++i){
            temp = head, curi=MAXI;
            while(curi>0 && temp->arr[index = (curi&nums[i]) != 0]) temp = temp->arr[index], curi >>= 1;
            for(;curi>0;curi>>=1) {
                index = (curi&nums[i]) != 0;
                temp->arr[index] = new TrieNode();
                temp = temp->arr[index];
            }
        }
        vector<int> ans(queries.size());
        for(int i{0};i<queries.size();++i) {
            ans[i] = maximizeXor(head, queries[i][0], queries[i][1], MAXI);
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        return maximizeXorTrie(nums, queries);
    }
};
