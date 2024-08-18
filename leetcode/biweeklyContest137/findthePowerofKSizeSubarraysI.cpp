/*
Q1. Find the Power of K-Size Subarrays I
You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all subarrays of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>res(nums.size() - k + 1, -1);
        for(int i = 0 ; i <= nums.size() - k; i++){
            int temp = nums[i];
            bool flag = true;
            for(int j = 1 ; j < k; j++){
                if(nums[i+j] != temp + j){
                    flag = false;
                    break;
                }
            }
                if(flag == true){
                    res[i] = nums[i+k-1];
                }  
        }
        return res;
    }
};

