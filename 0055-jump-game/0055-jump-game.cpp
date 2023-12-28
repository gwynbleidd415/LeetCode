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
        // int n{(int)nums.size()};
        // vector<bool> canJump(n);
        // canJump[n-1] = true;
        // int temp{};
        // for(int i{n-2};i>=0;--i){
        //     temp = nums[i] + i + 1;
        //     if(temp >= n) {
        //         canJump[i] = true;
        //         continue;
        //     }
        //     for(int j{i+1};j<temp;++j){
        //         if(canJump[j]) {
        //             canJump[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return canJump[0];

        // int n{(int)nums.size()};
        // vector<int> lji(n);
        // lji.back() = n-1;
        // int temp{};
        // for(int i{n-2}; i>=0 ; --i){
        //     if(nums[i]+i >= lji[i+1]) lji[i] = i;
        //     else lji[i] = lji[i+1];
        // }
        // return lji.front() == 0;

        int n{(int)nums.size()};
        int lastPos{n-1};
        for(int i{n-2}; i>=0 ; --i){
            if(nums[i]+i >= lastPos) lastPos = i;
        }
        return lastPos == 0;
    }
};