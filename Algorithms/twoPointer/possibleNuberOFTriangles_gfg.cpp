/*
Given an unsorted array of positive integers, find the number of possible triangles that can be formed with three different array elements as lengths of three sides of triangles.

Time Complexity: O(n^2), where n is the size of the array
Space Complexity: O(1)

For a triangle to be possible from 3 values, the sum of any two sides must be greater than the third side:
- a + b > c
- b + c > a
- a + c > b

Note: After sorting, we only need to check if the sum of first two elements is greater than the third
element since the array is sorted, other conditions will automatically be satisfied.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int> &arr)
    {
        int res = 0;
        sort(arr.begin(), arr.end());

        for (int i = 2; i < arr.size(); ++i)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (arr[left] + arr[right] > arr[i])
                {
                    res += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};
