/*
Problem Statement: Given an array of integers 'arr' and a number x, find the number of subarrays having XOR of their elements equal to x.

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: arr = [4, 2, 2, 6, 4], x = 6
Output: 4
Explanation: Subarrays having XOR of elements equal to 6 are: [4,2], [2,2,6], [6], [2,2,6,4]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int x)
    {
        map<int, int> freq;
        long count = 0;
        int xorr = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            xorr = xorr ^ arr[i];

            if (xorr == x)
            {
                count++;
            }

            if (freq.find(xorr ^ x) != freq.end())
            {
                count += freq[xorr ^ x];
            }

            freq[xorr]++;
        }

        return count;
    }
};

int main()
{
}