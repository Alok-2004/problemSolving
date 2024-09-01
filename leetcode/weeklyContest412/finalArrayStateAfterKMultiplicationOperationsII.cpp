/*
Q3. Final Array State After K Multiplication Operations II
You are given an integer array nums, an integer k, and an integer multiplier.
You need to perform k operations on nums. In each operation:
Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
After the k operations, apply modulo 109 + 7 to every value in nums.
Return an integer array denoting the final state of nums after performing all k operations and then applying the modulo. 
*/
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i], i});
        }
        
        for (int i = 0; i < k; ++i) {
            pair<int, int> minElem = minHeap.top();
            minHeap.pop();
            
            long long int newValue = static_cast<long long int>(minElem.first) * multiplier;
            newValue %= 1000000007;
            
            nums[minElem.second] = static_cast<int>(newValue);
            
            minHeap.push({nums[minElem.second], minElem.second});
        }
        
        return nums;
    }
};
