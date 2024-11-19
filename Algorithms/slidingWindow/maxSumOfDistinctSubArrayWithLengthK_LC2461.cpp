/*
2461. Maximum Sum of Distinct Subarrays With Length K
You are given an integer array nums and an integer k. 
Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. 
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>um; // element and its count
        long long res = 0;
        long long temp = 0;
        for(int i = 0 ; i < k ; i++){
            um[nums[i]]++;
            temp += nums[i];
        }
        if(k == um.size()) res = temp;


        for(int i = 1 ; i <= nums.size() - k ; i++){
            if(--um[nums[i-1]] == 0){
                um.erase(nums[i-1]);
            }
            temp = temp - nums[i-1] + nums[i+k-1];
            um[nums[i+k-1]]++;
            if(k == um.size()){
                res = max(res , temp);
            }
        }

        return res;
    }
};

int main(){
	
}

