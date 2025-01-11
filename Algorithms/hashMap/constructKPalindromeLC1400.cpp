/*
1400. Construct K Palindrome Strings
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return false;

        unordered_map<char, int> mp;
        for (auto ele : s)
        {
            mp[ele]++;
        }

        int countOfOdd = 0;
        for (auto ele : mp)
        {
            if (ele.second % 2 != 0)
                countOfOdd++;
        }

        return countOfOdd <= k;
    }
};

int main()
{
}