#include<bits/stdc++.h>
using nameaspace std;

class Solution {
public:
	
	// Brute force
	/*
    int searchInsert(vector<int>& nums, int target) {
        int idx = nums.size();
        for(int i = 0; i<nums.size(); i++){
        	if(nums[i] == target){
        		idx = i;
        		break;
			}
			if(nums[i] > target){	
				idx = i;
				break;
			}			
		}
		
		return idx;
    }
    */
    
    // Binary Search
    int searchInsert(vector<int>& nums, int tar){
    	int n = nums.size();
		int idx = n;
		
		if(nums[n - 1] < tar){
			return idx;
		}
		
		int i = 0, j = n - 1;
		while(i <= j){
			int mid = i + (j - i) / 2;
			if(nums[mid] == tar){
				idx = mid;
				break;
			}
			
			if(tar > nums[mid]){
				i = mid + 1;
			}else{
				j = mid - 1
			}
			idx = i;  
		}
		
		return idx;
	}
};

