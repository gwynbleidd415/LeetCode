class Solution {
private:
    vector<string> solution1(string &s) {
        int n = s.size();
        vector<int> start(26,-1), end(26,-1);
        for(int i{0};i<n;++i) {
            int ind = s[i] - 'a';
            if(start[ind] == -1) start[ind] = i;
            end[ind] = i;
        }
        vector<bool> cantKeep(26);
        for(int i{0};i<26;++i) {
            if(start[i] == -1) {
                continue;
            }
            for(int j{start[i]+1};j<end[i];++j) {
                int ind = s[j] - 'a';
                if(start[ind] < start[i]) {
                    cantKeep[i] = true;
                    break;
                }
                if(start[ind] == j) end[i] = max(end[i], end[ind]);
            }
        }
        vector<string> ans;
        int cut = INT_MAX;
        for(int i{n-1};i>=0;--i) {
            int ind = s[i] - 'a';
            if(cantKeep[ind] || start[ind] != i || end[ind]>cut) continue;
            cut = i;
            ans.push_back(s.substr(i, end[ind]-i+1));
        }
        return ans;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        return solution1(s);
    }
};
