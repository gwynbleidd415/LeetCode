class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size(), j, k;
        for(int i{0}; i <= n-m;++i){
            j = 0, k = i;
            while(j < m && needle[j] == haystack[k]){
                ++j, ++k;
            }
            if(j == m) return i;
        }
        return -1;
    }
};