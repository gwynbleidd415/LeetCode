class Solution {
private:
    string solution1(string &s, int numRows) {
        int n = s.size();
        if(numRows >= n || numRows == 1) return s;
        string ans{""};
        for(int i{0};i<numRows;++i) {
            bool isUp{false};
            int j{i};
            ans.push_back(s[j]);
            while(true) {
                int k{j};
                if(isUp) j += i<<1;
                else j += (numRows-i-1)<<1;
                cout << j << ' ';
                if(j>=n) break;
                if(k!=j) ans.push_back(s[j]);
                isUp = !isUp; 
            }
        }
        return ans;
    }
public:
    string convert(string s, int numRows) {
        return solution1(s, numRows);
    }
};