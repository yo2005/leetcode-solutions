class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>leftmax;
    priority_queue<int,vector<int>,greater<int>>rightmin;
    
    void addNum(int num) {
        leftmax.push(num);
        rightmin.push(leftmax.top());
        leftmax.pop();
        if(rightmin.size()>leftmax.size()){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }

        
    }
    
    double findMedian() {
        
        if(leftmax.size()>rightmin.size()){
            return leftmax.top();
        }
        return (leftmax.top()+rightmin.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
