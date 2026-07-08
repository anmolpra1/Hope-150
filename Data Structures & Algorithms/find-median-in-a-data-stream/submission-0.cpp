class MedianFinder {
    priority_queue<int> maxHeap; // to store the smaller half of the list
    priority_queue<int, vector<int>, greater<int>> minHeap; // to store thr larger half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: If minHeap has more elements, move top back to maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If both heaps are of equal size, take the average of the tops
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // If odd size, the top of maxHeap is the median
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */