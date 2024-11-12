/*
1671. Minimum Number of Removals to Make Mountain Array
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums???, return the minimum number of elements to remove to make nums??? a mountain array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
    
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (left[i] > 1 && right[i] > 1) {
                maxMountainLength = max(maxMountainLength, left[i] + right[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};


int main(){
	
}
