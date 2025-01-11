/**
 * Finds the length of the longest consecutive subsequence in an array
 *
 * Given an array of integers, this function finds the length of the longest subsequence
 * of consecutive integers that can be formed from the array elements.
 * A subsequence is a sequence that can be derived from another sequence by deleting some
 * or no elements without changing the order of the remaining elements.
 *
 * Example:
 * Input: arr[] = {2,6,1,9,4,5,3}
 * Output: 6
 * Explanation: The consecutive numbers are 1, 2, 3, 4, 5, 6
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N) where N is size of input array
 *
 * @param arr Array of integers
 * @param N Size of the array
 * @return int Length of longest consecutive subsequence
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s;
        for (int i = 0; i < N; i++)
        {
            s.insert(arr[i]);
        }

        int longestSeq = 0;

        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) == s.end())
            {
                int currentNum = arr[i];
                int currentSeq = 1;

                while (s.find(currentNum + 1) != s.end())
                {
                    currentNum++;
                    currentSeq++;
                }

                longestSeq = max(longestSeq, currentSeq);
            }
        }

        return longestSeq;
    }
};