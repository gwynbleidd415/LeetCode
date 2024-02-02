class Solution {
    int solution1(string &s) {
        int n = s.size();
        if(n <= 1) return n;

        int ans = 1;
        int sws = 0, swe = 1;
        vector<bool> visited(256, false);
        visited[s[0]] = true;

        while(swe < n){
            while(visited[s[swe]]){
                visited[s[sws++]] = false;
            }
            visited[s[swe++]] = true;
            ans = max(ans, swe-sws);
        }

        return ans;
    }
    int solution2(string &s) {
        int n = s.size();
        if(n <= 1) return n;

        int ans = 1;
        int sws = 0, swe = 1;
        vector<int> visited(256, -1);
        visited[s[0]] = 0;

        while(swe < n){
            if(visited[s[swe]] != -1){
                ans = max(ans, swe-sws);
                sws = max(sws, visited[s[swe]] + 1);
            }
            visited[s[swe]] = swe++;
        }
        return max(ans, swe-sws);
    }
public:
    int lengthOfLongestSubstring(string s) {
        // return solution1(s);
        return solution2(s);
    }
};