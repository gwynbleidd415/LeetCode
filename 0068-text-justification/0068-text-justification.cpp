class Solution {
private:
    string getJustified(int start, int end, int cLen, int maxWidth, vector<string>& words) {
        int nWords = end - start;
        if(nWords == 0) {
            string str = words[start];
            for(int i{cLen};i<maxWidth;++i) str.push_back(' ');
            return str;
        }
        int extraSpaces = (maxWidth - cLen) / nWords;
        int eextraSpaces = maxWidth - cLen - extraSpaces * nWords;
        ++extraSpaces;
        string ans{""};
        for(int i{start};i<end;++i) {
            ans += words[i];
            for(int j{0};j<extraSpaces;++j) ans.push_back(' ');
            if(eextraSpaces) {
                ans.push_back(' ');
                --eextraSpaces;
            }
        }
        ans += words[end];
        return ans;
    }
    string getLeftJustified(int start, int end, int cLen, int maxWidth, vector<string>& words) {
        string ans{""};
        for(int i{start};i<end;++i) {
            ans += words[i];
            ans.push_back(' ');
        }
        ans += words[end];
        for(int i{cLen};i<maxWidth;++i) ans.push_back(' ');
        return ans;
    }
    vector<string> solution1(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start{0}, cLen = words.front().size();
        for(int end{1};end<words.size();++end) {
            if(cLen + words[end].size() + 1 > maxWidth) {
                ans.push_back(getJustified(start, end-1, cLen, maxWidth, words));
                start = end;
                cLen = words[end].size();
            } else {
                cLen += words[end].size() + 1;
            }
        }
        ans.push_back(getLeftJustified(start, words.size()-1, cLen, maxWidth, words));
        return ans;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        return solution1(words, maxWidth);
    }
};