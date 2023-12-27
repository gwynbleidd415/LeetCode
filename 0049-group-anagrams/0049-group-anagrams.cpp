class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        string str1;
        for(string &str: strs){
            str1 = str;
            sort(str1.begin(), str1.end());
            umap[str1].push_back(str);
        }
        vector<vector<string>> ans;
        for(pair<const string, vector<string>> &umapel: umap){
            ans.push_back(umapel.second);
        }
        return ans;
    }
};