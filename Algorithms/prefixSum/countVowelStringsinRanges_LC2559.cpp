/*
2559. Count Vowel Strings in Ranges

You are given a 0-indexed array of strings words and a 2D array of integers queries.

For each query queries[i] = [li, ri], you need to:
1. Count the number of strings in words that start and end with a vowel and
    are present in the range li to ri (inclusive).
2. Return an array ans of size queries.length, where ans[i] is the answer to
    the ith query.

Note: The vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Example:
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation:
Query [0,2]: "aba" and "ece" count (2 strings)
Query [1,4]: "ece", "aa", "e" count (3 strings)
Query [1,1]: "bcb" doesn't count (0 strings)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) &&
                vowels.count(currentWord[currentWord.size() - 1]))
            {
                sum++;
            }
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
        }

        return ans;
    }
};

int main()
{
}