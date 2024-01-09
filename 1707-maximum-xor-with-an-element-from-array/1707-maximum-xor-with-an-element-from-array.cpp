class Solution {
private:
    struct TrieNode {
        TrieNode *arr[2];
        TrieNode() {
            arr[0] = arr[1] = nullptr;
        }
    };
    int maximizeXorMaxx1(TrieNode *trie, int xr, int curi) {
        if(curi == 0) return 0;
        bool ii = (xr&curi) == 0;
        if(trie->arr[ii]) return curi^maximizeXorMaxx1(trie->arr[ii], xr, curi>>1);
        return maximizeXorMaxx1(trie->arr[!ii], xr, curi>>1);
    }
    int maximizeXor1(TrieNode *trie, int xr, int mx, int curi) {
        if(trie == nullptr) return -1;
        if(curi == 0) return 0;
        bool ind = (mx&curi) != 0;
        if(ind) {
            int ans1 = maximizeXor1(trie->arr[1], xr, mx, curi>>1);
            int ans2 = trie->arr[0] ? maximizeXorMaxx1(trie->arr[0], xr, curi>>1) : -1;
            if(ans1 == -1) {
                if(ans2 == -1) return -1;
                return (xr&curi)^ans2;
            }
            if(ans2 == -1) return (xr&curi)^curi^ans1;
            return max((xr&curi)^curi^ans1, (xr&curi)^ans2);
        } else {
            int ans = maximizeXor1(trie->arr[0], xr, mx, curi>>1);
            if(ans!=-1) return (xr&curi)^ans;
            else return -1;
        }
    }
    vector<int> maximizeXorTrie1(vector<int>& nums, vector<vector<int>>& queries) {
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
            ans[i] = maximizeXor1(head, queries[i][0], queries[i][1], MAXI);
        }
        return ans;
    }
    void insertIntoTrie(TrieNode *trie, int n) {
        TrieNode *temp = trie;
        int curr = 1<<30;
        bool index;
        for(;curr!=0 && trie->arr[index=(curr&n)!=0];curr >>= 1) {
            trie = trie->arr[index];
        }
        for(;curr!=0;curr >>= 1) {
            index = (curr&n)!=0;
            trie->arr[index] = new TrieNode();
            trie = trie->arr[index];
        }
    }
    int maximizeXor2(TrieNode *trie, int n) {
        int curr = 1<<30;
        int index;
        int ans{0};
        while(curr) {
            index = (n&curr) == 0;
            if(trie->arr[index]) {
                ans = ans ^ curr;
                trie = trie->arr[index];
            } else {
                trie = trie->arr[!index];
            }
            curr >>= 1;
        }
        return ans;
    }
    vector<int> maximizeXorTrie2(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ind(n), ans(n);
        iota(ind.begin(), ind.end(), 0);
        sort(nums.begin(), nums.end());
        sort(ind.begin(), ind.end(), [&queries](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        TrieNode *trie = new TrieNode();
        int j{0};
        for(int i{0};i<n;++i) {
            while(j<nums.size() && nums[j] <= queries[ind[i]][1]) insertIntoTrie(trie, nums[j]), ++j;
            if(j == 0) ans[ind[i]] = -1;
            else ans[ind[i]] = maximizeXor2(trie, queries[ind[i]][0]);
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // return maximizeXorTrie1(nums, queries);
        return maximizeXorTrie2(nums, queries);
    }
};
