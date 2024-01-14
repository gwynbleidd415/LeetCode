class Solution {
private:
    string solution1(vector<string>& strs) {
        int tri = 0;
        char currCh;
        bool continueLoop = true;
        while(true){
            if(strs[0].size() > tri){
                currCh = strs[0][tri];
            } else {
                break;
            }
            for(int i{1};i<strs.size();++i){
                if(strs[i].size() > tri && strs[i][tri] == currCh){
                    continue;
                } else {
                    continueLoop = false;
                    break;
                }
            }
            if(continueLoop){
                ++tri;
            } else {
                break;
            }
        }
        return strs[0].substr(0, tri);
    }
    string solution2(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int len = 0;
        for(int i{0}; i< min(strs.front().size(), strs.back().size()); ++i){
            if(strs.front()[i] != strs.back()[i]){
                break;
            } else {
                ++len;
            }
        }
        return strs.front().substr(0, len);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return solution1(strs);
        // return solution2(strs);
    }
};
