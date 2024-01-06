class Solution {
    int solution1(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        vector<int> count(26);
        for(char &task: tasks) ++count[task-'A'];
        priority_queue<int> pq;
        for(int ct: count) if(ct) pq.push(ct);
        int ans{0};
        vector<int> store;
        while(pq.size()>n) {
            store.clear();
            for(int i{0};i<=n;++i) {
                store.push_back(pq.top()-1), pq.pop();
            }
            ++ans;
            for(int i{0};i<=n;++i) {
                if(store[i]) pq.push(store[i]);
                else break;
            }
        }
        ans *= (n+1);
        if(!pq.empty()) {
            int temp{pq.top()}, cnt{1};
            pq.pop();
            while(!pq.empty() && temp == pq.top()) pq.pop(), ++cnt;
            ans += (temp-1)*(n+1) + cnt;
        }
        return ans;
    }
    int solution2(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int> count(26);
        for(char &task: tasks) ++count[task-'A'];
        sort(count.begin(), count.end(), greater<int>());
        int cnt{0};
        for(int cc: count) {
            if(cc == count.front()) ++cnt;
            else break;
        }
        return max((count.front()-1)*(n+1) + cnt, (int)tasks.size());
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        // return solution1(tasks, n);
        return solution2(tasks, n);
    }
};
