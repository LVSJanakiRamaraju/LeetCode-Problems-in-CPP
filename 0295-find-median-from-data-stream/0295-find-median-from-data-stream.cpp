class MedianFinder {
public:
    MedianFinder() {
        
    }
    int sum =0;
    int count =0;
    
    void addNum(int num) {
        sum += num;
        count++;
    }
    
    double findMedian() {
        return (double)sum/count;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */