/*
Max Circular Subarray Sum
Given an array of integers arr[] in a circular fashion. 
Find the maximum subarray sum that we can get if we assume the array to be circular.
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force
/*
class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size(), maxSum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = 0; j < n; ++j) {
                currentSum += arr[(i + j) % n];
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
*/

class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0, currentMin = 0, currentMax = 0, minSubarraySum = INT_MAX, maxSubarraySum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            totalSum += arr[i];
            currentMin = min(arr[i], currentMin + arr[i]);
            minSubarraySum = min(minSubarraySum, currentMin);
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSubarraySum = max(maxSubarraySum, currentMax);
        }
        if (maxSubarraySum < 0) return maxSubarraySum;
        return max(maxSubarraySum, totalSum - minSubarraySum);
    }
};

int main(){
	
}
