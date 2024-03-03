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
public:
    int totalNQueens(int n) {
        return solution1(n);
    }
};