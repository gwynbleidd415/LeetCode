class Solution {
private:
    vector<int> solution1(vector<int> &deck) {
        deque<int> dq;
        sort(deck.begin(), deck.end());
        int i = deck.size() - 1;
        vector<int> ans; ans.reserve(deck.size());
        dq.push_back(deck[i]); --i;
        while(i>=0) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
            --i;
        }
        for(i=0;i<deck.size();++i) ans.push_back(dq.front()), dq.pop_front();
        return move(ans);
    }
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        return solution1(deck);
    }
};