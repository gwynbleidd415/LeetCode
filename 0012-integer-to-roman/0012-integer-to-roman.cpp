class Solution {
private:
    string solution1(int num) {
        string ans{""};
        pair<int, char> arr[7] = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        for(int i{6};i>1 && num>0;i-=2) {
            int cnt = num/arr[i].first;
            num -= cnt*arr[i].first;
            while(cnt) ans.push_back(arr[i].second), --cnt;
            if(num >= arr[i].first - arr[i-2].first) {
                ans.push_back(arr[i-2].second), ans.push_back(arr[i].second);
                num -= arr[i].first - arr[i-2].first;
            }
            if(num >= arr[i-1].first) {
                ans.push_back(arr[i-1].second);
                num -= arr[i-1].first;
            }
            if(num >= arr[i-1].first - arr[i-2].first) {
                ans.push_back(arr[i-2].second), ans.push_back(arr[i-1].second);
                num -= arr[i-1].first - arr[i-2].first;
            }
        }
        while(num) ans.push_back(arr[0].second), --num;
        return ans;
    }
public:
    string intToRoman(int num) {
        return solution1(num);
    }
};