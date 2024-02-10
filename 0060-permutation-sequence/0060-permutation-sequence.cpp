class Solution {
private:
    void solution1Helper(int ind, string &curr, vector<bool> &taken, int n, int &k) {
        if(ind == n) {
            --k;
            return;
        }
        for(int i{0};i<n;++i) {
            if(taken[i]) continue;
            curr.push_back('0' + (char)(i+1));
            taken[i] = true;
            solution1Helper(ind+1, curr, taken, n, k);
            if(k == 0) return;
            curr.pop_back();
            taken[i] = false;
        }
    }
    string solution1(int n, int k) {
        string curr;
        vector<bool> taken(n, false);
        int cnt{0};
        solution1Helper(0, curr, taken, n, k);
        return curr;
    }
public:
    string getPermutation(int n, int k) {
        return solution1(n, k);
    }
};