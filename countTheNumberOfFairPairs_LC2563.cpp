/*
2563. Count the Number of Fair Pairs
Given a 0-indexed integer array nums of size n and two integers lower and upper, 
return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
*/

#include<bits/stdc++.h>
using namespace std;

// Using brute force approach will give TLE
/*
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        long long count = 0;
        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() - 1 ; i++){

            for(int j = i+1; j < nums.size() ; j++){
                if(nums[i] + nums[j] >= l and nums[i] + nums[j] <= u){
                    count++;
                    // cout<< nums[i] << " " << nums[j]<<endl;
                }else if(nums[i] + nums[j] > u){
                    break;
                }
            }
        }

        return count;
    }
};
*/

// Using Two ppointers
class Solution {
public:
	
    long long countPairs(vector<int>& nums, int target) {
        long long count = 0;
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] > target) right--;
            else {
                count += right - left;
                left++;
            }
        }
        return count;
    }
	
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }
    
};

int main(){
	
}
