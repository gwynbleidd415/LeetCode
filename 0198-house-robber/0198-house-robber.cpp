class Solution {
    int solution1(vector<int> &nums) {
        pair<int, int> taig{0, 0};
        int temp;
        for(int num: nums) {
            temp = taig.second;
            taig.second = max(taig.first, taig.second);
            taig.first = temp + num;
        }
        return max(taig.first, taig.second);
    }
public:
    int rob(vector<int>& nums) {
        return solution1(nums);
    }
};