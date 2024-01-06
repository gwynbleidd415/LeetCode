class Solution {
public:
    int romanToInt(string s) {
        vector<int> arr(26, 0);
        arr['I'-'A'] = 1; 
        arr['V'-'A'] = 5; 
        arr['X'-'A'] = 10; 
        arr['L'-'A'] = 50; 
        arr['C'-'A'] = 100; 
        arr['D'-'A'] = 500; 
        arr['M'-'A'] = 1000;
        int n = s.size();
        int ans = 0;
        for(int i{0};i<n-1;++i){
            if(arr[s[i+1] - 'A'] > arr[s[i] - 'A']) ans -= arr[s[i] - 'A'];
            else ans += arr[s[i] - 'A'];
        }
        ans += arr[s.back() - 'A'];
        return ans;
    }
};
