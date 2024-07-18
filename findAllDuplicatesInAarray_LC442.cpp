/*
442. Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

#include<bits/stdc++.h>
uisng namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums){
  		int count = 0;
		for(int i = 0; i < nums.size(); i++){
  			int ele = nums[i];
			if(nums[i] != nums[ele - 1]){
				swap(nums[ele - 1], nums[i]);
			}	
		}
		
		for(int i = 0; i < nums.size(); i++){
			int ele = nums[i];
			if(nums[i] != nums[ele - 1]){
				count++;
			}
		}
		
		return count;  	
	}
};
