/*
862. Shortest Subarray with Sum at Least K
Given an integer array nums and an integer k, 
return the length of the shortest non-empty subarray of nums with a sum of at least k.
 If there is no such subarray, return -1.

A subarray is a contiguous part of an array.
*/

#include<bits/stdc++.h>
using namespace tsd;

//Brute Force
// TLE
/*
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (sum >= k) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
*/

//Issue with this Approach that For negative values in the array this code will go boom 
//(specially if we use Sliding window or two pointers approach)
/*
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        int localSum = 0;
        int left = 0;
        int right = 0;

        while(right < nums.size()){
            if(localSum < k){
                localSum += nums[right];
                cout<<localSum<<endl;
                right++;
            }else if(localSum >= k ){
                localSum = localSum - nums[left];
                left++;
                res = min(right - left + 1 , res);
            }
        }

        if(localSum == k){
            res = min(static_cast<int>(nums.size()) - 1 - left + 1 , res);
        }

        return res == INT_MAX ? -1 : res;
    }
};
*/

//Now using Queue 
//correct method

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq; // Stores index in monotonic order of cumulativeSum
        vector<long long> cumulativeSum(n + 1, 0);

        int res = INT_MAX;

        for (int j = 0; j < n; ++j) {
            cumulativeSum[j + 1] = cumulativeSum[j] + nums[j];

            if (cumulativeSum[j + 1] >= k) {
                res = min(res, j + 1);
            }

            // Need to shrink the window or not
            while (!deq.empty() && cumulativeSum[j + 1] - cumulativeSum[deq.front()] >= k) {
                res = min(res, j + 1 - deq.front());
                deq.pop_front();
            }
            while (!deq.empty() && cumulativeSum[j + 1] <= cumulativeSum[deq.back()]) {
                deq.pop_back();
            }

            deq.push_back(j + 1);
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main(){
	
}
