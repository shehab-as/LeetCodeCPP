class MedianFinder {
private:
    vector<int> A;
    bool even;
public:
    /** initialize your data structure here. */
    MedianFinder() : even(true)  {
        
    }
    
    void addNum(int num) {
        even = (even) ? false : true;
        auto it = lower_bound(A.begin(), A.end(), num);
        A.insert(it, num);
    }
    
    double findMedian() {
        int n = A.size();
        return (even) ?( ((double)A[n/2] + (double)A[n/2 - 1]) / 2 ) : double(A[(n/2)]);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */