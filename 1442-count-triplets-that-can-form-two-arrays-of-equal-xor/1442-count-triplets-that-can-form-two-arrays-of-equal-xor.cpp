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
public:
    int countTriplets(vector<int>& arr) {
        return solution1(arr);
    }
};
