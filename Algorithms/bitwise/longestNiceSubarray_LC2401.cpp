/*
2401. Longest Nice Subarray
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), usedBits = 0, right = 0, left = 0, maxLen = 0;

        while(right < n){
            while((usedBits & nums[right]) != 0){
                usedBits ^= nums[left];
                left++;
            }

            usedBits |= nums[right];
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main(){
	
}
