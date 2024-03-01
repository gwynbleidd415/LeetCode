class Solution {
private:
    vector<int> solution1(string &s, vector<string>& words) {
        int n = words.size();
        int l = words.front().size();
        int m = l * n;
        int k = s.size();
        vector<int> ans;
        if(k<m) return ans;
        unordered_map<string, pair<vector<int>, int>> umap;
        unordered_map<string, pair<vector<int>, int>>::iterator uitr;
        vector<int> isPresent(n, -1);
        vector<int> whatPresent(k, -1);
        for(int i{0};i<n;++i) umap[words[i]].first.push_back(i);
        int last = k-m, last2 = k-l;
        for(int i{0};i<l;++i) {
            for(int y{i};y<=last2;y+=l) {
                if((uitr = umap.find(s.substr(y, l))) != umap.end()) {
                    whatPresent[y] = uitr->second.first[uitr->second.second];
                    ++uitr->second.second;
                    if(uitr->second.second == uitr->second.first.size()) uitr->second.second = 0;
                }
            }
            for(int &ip: isPresent) ip = -1;
            int count{0}, j{i};
            for(;j<i+m;j+=l) {
                if(whatPresent[j] != -1) {
                    if(isPresent[whatPresent[j]] == -1) ++count;
                    isPresent[whatPresent[j]] = j;
                }
            }
            if(count == n) ans.push_back(j-m);
            for(;j<=last2;j+=l) {
                int x = j-m;
                if(whatPresent[x] != -1 && isPresent[whatPresent[x]] == x) {
                    --count;
                }
                if(whatPresent[j] != -1) {
                    if(isPresent[whatPresent[j]] <= x) ++count;
                    isPresent[whatPresent[j]] = j;
                }
                if(count == n) ans.push_back(j-m+l);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return solution1(s, words);
    }
};