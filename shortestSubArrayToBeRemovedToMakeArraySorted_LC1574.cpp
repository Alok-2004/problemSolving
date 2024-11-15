/*
1574. Shortest Subarray to be Removed to Make Array Sorted
Given an integer array arr, remove a subarray (can be empty) from arr such that the 
remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int left = 0;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        if (left == n - 1) {
            return 0;
        }
        
        int right = n - 1;
        while (right > left && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        int result = min(n - left - 1, right);
        
        for (int i = 0; i <= left; i++) {
            while (right < n && arr[i] > arr[right]) {
                right++;
            }
            result = min(result, right - i - 1);
        }
        
        return result;
    }
};



int main(){
	
}
