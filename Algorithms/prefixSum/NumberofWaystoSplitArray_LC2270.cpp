/*

2270. Number of Ways to Split Array

You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.

Return the number of valid splits in nums.

Example 1:
Input: nums = [10,4,-8,7]
Output: 2

Example 2:
Input: nums = [2,3,1,0]
Output: 2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long totalSum = 0, prefixSum = 0;

        for (int num : nums)
        {
            totalSum += num;
        }

        int cnt = 0;

        for (int i = 0; i < n - 1; i++)
        {
            prefixSum += nums[i];
            if (prefixSum >= (totalSum - prefixSum))
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
}