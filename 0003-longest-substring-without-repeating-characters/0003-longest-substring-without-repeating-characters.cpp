class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;

        int ans = 1;
        int sws = 0, swe = 1;
        vector<bool> visited(256, false);
        visited[s[0]] = true;

        while(swe < n){
            while(visited[s[swe]] == true){
                visited[s[sws++]] = false;
            }
            visited[s[swe++]] = true;
            ans = max(ans, swe-sws);
        }

        return ans;
    }
};