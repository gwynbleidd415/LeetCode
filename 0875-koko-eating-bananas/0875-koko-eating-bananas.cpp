class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = *max_element(piles.begin(), piles.end());
        int l{1}, r{k}, mid, th;
        while(l<r){
            mid = (l+r) >> 1;
            th = 0;
            for(int pile: piles) th += pile/mid + (pile%mid == 0 ? 0 : 1);
            // cout<<l<<' '<<mid<<' '<<r<<' '<<th<<'\n';
            if(th>h) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};