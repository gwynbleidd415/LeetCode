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
    void solution2Helper(int ind, int &curr, vector<bool> &taken, int n, int &k) {
        if(ind == n) {
            --k;
            return;
        }
        for(int i{0};i<n;++i) {
            if(taken[i]) continue;
            curr = curr * 10 + i + 1;
            taken[i] = true;
            solution2Helper(ind+1, curr, taken, n, k);
            if(k == 0) return;
            curr /= 10;
            taken[i] = false;
        }
    }
    string solution2(int n, int k) {
        int curr;
        vector<bool> taken(n, false);
        int cnt{0};
        solution2Helper(0, curr, taken, n, k);
        return to_string(curr);
    }
    string solution3(int n, int k) {
        string curr{""};
        vector<bool> taken(n, false);
        vector<int> factorial(n);
        factorial[0] = 1, factorial[1] = 1;
        for(int i{2};i<n;++i) factorial[i] = factorial[i-1] * i;
        int temp, mod;
        --k;
        for(int i{n-1};i>0;--i) {
            temp = k / factorial[i];
            int count = -1;
            for(int j{0};j<n;++j) {
                if(taken[j]) continue;
                ++count;
                if(count == temp) {
                    taken[j] = true;
                    curr.push_back('0' + (char)(j+1));
                    break;
                }
            }
            k = k - temp * factorial[i];
        }
        for(int j{0};j<n;++j) {
            if(taken[j]) continue;
            curr.push_back('0' + (char)(j+1));
            break;
        }
        return curr;
    }
public:
    string getPermutation(int n, int k) {
        // return solution1(n, k);
        // return solution2(n, k);
        return solution3(n, k);
    }
};