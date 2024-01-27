class DisjointSet {
private:
    vector<int> par;
    vector<int> sz;
public:
    DisjointSet(int n) {
        par.resize(n), sz.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find(int i) {
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }
    void unite(int i, int j) {
        int pari{find(i)}, parj{find(j)};
        if(pari == parj) return;
        if(sz[parj] > sz[pari]) swap(pari, parj);
        par[parj] = pari;
        sz[pari] += sz[parj];
    }
};

class Solution {
private:
    vector<vector<string>> solution1(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> umap;
        unordered_map<string, int>::iterator uitr;
        DisjointSet dj(n);
        for(int i{0};i<n;++i) {
            for(int j{1};j<accounts[i].size();++j) {
                uitr = umap.find(accounts[i][j]);
                if(uitr == umap.end()) {
                    umap[accounts[i][j]] = i;
                } else {
                    dj.unite(uitr->second, i);
                }
            }
        }
        vector<int> szmap(n, -1);
        int count{0};
        vector<vector<string>> ans;
        int parr;
        for(auto &uitr1: umap) {
            parr = dj.find(uitr1.second);
            if(szmap[parr] == -1) {
                szmap[parr] = count++;
                ans.push_back(vector<string>{accounts[parr][0]});
            }
            ans[szmap[parr]].push_back(uitr1.first);
        }
        for(auto &itr: ans) {
            sort(itr.begin()+1, itr.end());
        }
        return ans;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        return solution1(accounts);
    }
};