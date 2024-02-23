class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0) {
            maxpq.push(num);
        } else {
            if(num <= maxpq.top()) {
                maxpq.push(num);
                if(size & 1) {
                    minpq.push(maxpq.top());
                    maxpq.pop();
                }
            } else {
                minpq.push(num);
                if(!(size & 1)) {
                    maxpq.push(minpq.top());
                    minpq.pop();
                }
            }
        }
        ++size;
    }
    
    double findMedian() {
        if(size & 1) return maxpq.top();
        return ((double)maxpq.top() + minpq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */