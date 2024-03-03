class Solution {
private:
    void solution1Helper(int ci, int &count, vector<int> &posFilled) {
        if(ci == posFilled.size()) {
            ++count;
            return;
        }
        for(int i{0};i<posFilled.size();++i) {
            bool isPossible{true};
            for(int j{0};j<ci;++j) {
                if(posFilled[j] == i || posFilled[j] + j == ci + i || posFilled[j] - j == i - ci) {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) {
                posFilled[ci] = i;
                solution1Helper(ci+1, count, posFilled);
            }
        }
    }
    int solution1(int n) {
        vector<int> posFilled(n);
        int count{0};
        solution1Helper(0, count, posFilled);
        return count;
    }
    void solution2Helper(int ci, int &count, int n, vector<bool> &posFilled, vector<bool> &diagFilled, vector<bool> &rdiagFilled) {
        if(ci == n) {
            ++count;
            return;
        }
        for(int i{0};i<n;++i) {
            if(posFilled[i] || diagFilled[i+ci] || rdiagFilled[ci-i + n-1]) continue;
            posFilled[i] = diagFilled[i+ci] = rdiagFilled[ci-i + n-1] = true;
            solution2Helper(ci+1, count, n, posFilled, diagFilled, rdiagFilled);
            posFilled[i] = diagFilled[i+ci] = rdiagFilled[ci-i + n-1] = false;
        }
    }
    int solution2(int n) {
        vector<bool> posFilled(n), diagFilled((n<<1)-1), rdiagFilled((n<<1)-1);
        int count{0};
        solution2Helper(0, count, n, posFilled, diagFilled, rdiagFilled);
        return count;
    }
public:
    int totalNQueens(int n) {
        // return solution1(n);
        return solution2(n);
    }
};