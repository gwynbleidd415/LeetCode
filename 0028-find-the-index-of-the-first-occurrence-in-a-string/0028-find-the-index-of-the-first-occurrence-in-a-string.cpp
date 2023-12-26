class Solution {
    int bruteForce(string &haystack, string &needle){
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
    int zAlgorithm(string &haystack, string &needle){
        string str = needle + "#" + haystack;
        int n = str.size(), m = needle.size();
        vector<int> zarr(n, 0);
        int i{1}, j{0}, k{1};
        while(i<n){
            while(k<n && str[k] == str[j]){
                ++j, ++k;
            }
            if(j == m){
                return i - (m+1);
            }
            zarr[i] = j;
            j = 1; ++i;
            while(zarr[j] + i < k){
                zarr[i] = zarr[j];
                ++i, ++j;
            }
            k = max(k, i);
            j = k-i;
        }
        return -1;
    }
    vector<int> kmpArray(string &needle){
        int n = needle.size();
        vector<int> arr(n);
        arr[0] = 0;
        int i{1}, j{0};
        while(i<n){
            if(needle[i] == needle[j]){
                arr[i] = j+1;
                ++i, ++j;
                continue;
            }
            if(j == 0){
                arr[i] = 0;
                ++i;
                continue;
            }
            j = arr[j-1];
        }
        return move(arr);
    }
    int kmpAlgorithm(string &haystack, string &needle){
        vector<int> kmpArr = kmpArray(needle);
        int n = haystack.size(), m = needle.size();
        int i{0},j{0};
        while(i<n){
            if(haystack[i] == needle[j]){
                ++i, ++j;
                if(j == m){
                    return i-j;
                }
                continue;
            }
            if(j == 0) {
                ++i;
                continue;
            }
            j = kmpArr[j-1];
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return bruteForce(haystack, needle);
        // return zAlgorithm(haystack, needle);
        // return kmpAlgorithm(haystack, needle);
    }
};