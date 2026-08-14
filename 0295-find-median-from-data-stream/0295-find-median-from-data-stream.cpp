#include <queue>
using namespace std;

class MedianFinder {
private:
    // Max-Heap: Stores the smaller half of numbers (top() = biggest of the small half)
    priority_queue<int> lowerHalf; 

    // Min-Heap: Stores the larger half of numbers (top() = smallest of the large half)
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    MedianFinder() {
        // Constructor (nothing to initialize manually)
    }
    
    void addNum(int num) {
        // STEP 1: Decide which heap to put 'num' in
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        } else {
            upperHalf.push(num);
        }

        // STEP 2: Keep the two halves balanced in size!
        // We allow lowerHalf to have AT MOST 1 extra element compared to upperHalf.
        
        // If lowerHalf gets too big, move its top element to upperHalf
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } 
        // If upperHalf gets bigger than lowerHalf, move its top element to lowerHalf
        else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        // Case 1: Total numbers is ODD
        // lowerHalf holds the single extra middle element
        if (lowerHalf.size() > upperHalf.size()) {
            return lowerHalf.top();
        }
        
        // Case 2: Total numbers is EVEN
        // Take the average of the middle two values
        return (lowerHalf.top() + upperHalf.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */