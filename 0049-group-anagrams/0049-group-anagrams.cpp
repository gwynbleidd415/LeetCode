class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        string str1;
        for(string &str: strs){
            str1 = str;
            sort(str1.begin(), str1.end());
            auto uitr = umap.find(str1);
            if(uitr != umap.end()){
                (uitr->second).push_back(str);
            } else {
                umap.insert({str1, {str}});
            }
        }
        vector<vector<string>> ans;
        for(auto &umapel: umap){
            ans.push_back(umapel.second);
        }
        return ans;
    }
};