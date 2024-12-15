/*
2779. Maximum Beauty of an Array After Applying Operation
You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:

Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
The beauty of the array is the length of the longest subsequence consisting of equal elements.

Return the maximum possible beauty of the array nums after applying the operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements
*/

#include<bits/stdc++.h>
using namespace std;

// Using line sweep
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> events;
        
        for (int num : nums) {
            events.push_back({num - k, 1});
            events.push_back({num + k + 1, -1}); 
        }
        
        sort(events.begin(), events.end());
        
        int active = 0, res = 0;
        for (const auto& event : events) {
            active += event.second;
            res = max(res, active);
        }
        
        return res;
    }
};

// Using Binary Search
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        
        for (int i = 0; i < n; ++i) {
            int target = nums[i] + 2 * k;
            int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            res = max(res, idx - i);
        }
        
        return res;
    }
};

// Using Normal Sorting
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int l = 0;
        int r = 0;
        int res = 0;
        while(l <= r and r < nums.size()){
            if(nums[r] - nums[l] <= 2*k){
                res = max(res , r - l + 1);
                r++;
            }else{
                l++;
            }
        }

        return res;
    }
};


int main(){
	
}
