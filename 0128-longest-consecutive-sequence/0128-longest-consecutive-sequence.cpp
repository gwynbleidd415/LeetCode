class DisjointSet {
private:
    vector<int> par, size;
public:
    DisjointSet(int n) {
        par.resize(n), size.resize(n);
        iota(par.begin(), par.end(), 0);
        fill(size.begin(), size.end(), 1);
    }
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    int unite(int x, int y) {
        int parx{find(x)}, pary{find(y)};
        if(parx == pary) return size[parx];
        if(size[pary] > size[parx]) swap(parx, pary);
        par[pary] = parx;
        size[parx] += size[pary];
        return size[parx];
    }
};

class Solution {
    int solution1(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        DisjointSet dj(nums.size());
        unordered_map<int, int> umap;
        unordered_map<int, int>::iterator uitr;
        int ans{1};
        for(int i{0};i<nums.size();++i) {
            if(umap.find(nums[i]) != umap.end()) continue;
            umap.insert({nums[i], i});
            uitr = umap.find(nums[i]-1);
            if(uitr != umap.end()) ans = max(ans, dj.unite(i, uitr->second));
            uitr = umap.find(nums[i]+1);
            if(uitr != umap.end()) ans = max(ans, dj.unite(i, uitr->second));
        }
        return ans;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        return solution1(nums);
    }
};
