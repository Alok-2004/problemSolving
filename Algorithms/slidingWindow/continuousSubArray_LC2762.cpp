/*
2762. Continuous Subarrays
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0;
        long long res = 0;  
        deque<int> minD, maxD;

        for (int r = 0; r < nums.size(); r++) {
            while (!minD.empty() && nums[minD.back()] >= nums[r]) minD.pop_back();
            while (!maxD.empty() && nums[maxD.back()] <= nums[r]) maxD.pop_back();
            minD.push_back(r);
            maxD.push_back(r);

            while (nums[maxD.front()] - nums[minD.front()] > 2) {
                l++;
                if (minD.front() < l) minD.pop_front();
                if (maxD.front() < l) maxD.pop_front();
            }

            res += r - l + 1;
        }

        return res;
    }
};




int main(){
	
}
