/*
703. Kth Largest Element in a Stream
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/

class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>>temp(nums.begin() , nums.end());
        pq = temp;
        this->k = k;

        while(pq.size() > k){
            pq.pop();
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};
