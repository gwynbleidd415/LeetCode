class Solution {
private:
    int solution1(vector<int>& arr) {
        int ans{0};
        for(int i{1};i<arr.size();++i) {
            arr[i] = arr[i] ^ arr[i-1];
            if(arr[i] == 0) ans += i; 
            for(int j{0};j<i;++j){
                if(arr[i] == arr[j]) ans+= i-j-1;
            }
        }
        return ans;
    }
    int solution2(vector<int>& arr) {
        unordered_map<int, vector<int>> umap;
        umap[0].push_back(0);
        int ans{0}, curx{0};
        for(int i{0};i<arr.size();++i) {
            curx ^= arr[i];
            for(int j{0};j<umap[curx].size();++j) ans += i - umap[curx][j];
            umap[curx].push_back(i+1);
        }
        return ans;
    }
    int solution3(vector<int>& arr) {
        int ans{0}, xorr;
        for(int i{0};i<arr.size();++i) {
            xorr = arr[i];
            for(int j{i+1};j<arr.size();++j){
                xorr ^= arr[j];
                if(xorr == 0) ans += j-i;
            }
        }
        return ans;
    }
public:
    int countTriplets(vector<int>& arr) {
        // return solution1(arr);
        // return solution2(arr);
        return solution3(arr);
    }
};
