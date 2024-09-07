/*
Indexes of Subarray Sum
Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) 
that has sum equal to s. 
You mainly need to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. 
If no such subarray exists return an array consisting of element -1.
*/


//Time complexity of O(n)
//Space complexity of O(1)
class Solution {
  public:
    
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        long long sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum += arr[j];
            while (sum > s and i < j) {
                sum -= arr[i];
                i++;
            }
            if (sum == s) {
                return {i + 1, j + 1};
            }
            j++;
        }
        return {-1};
    }
};

