class Solution {
private:
    // void printVector(vector<bool> &arr){
    //     for(auto it: arr){
    //         cout << it << ' ';
    //     }
    //     cout << '\n';
    // }
public:
    bool canJump(vector<int>& nums) {
        int n{(int)nums.size()};
        vector<bool> canJump(n);
        canJump[n-1] = true;
        int temp{};
        for(int i{n-2};i>=0;--i){
            temp = nums[i] + i + 1;
            if(temp >= n) {
                canJump[i] = true;
                continue;
            }
            for(int j{i+1};j<temp;++j){
                if(canJump[j]) {
                    canJump[i] = true;
                    break;
                }
            }
        }
        return canJump[0];
    }
};