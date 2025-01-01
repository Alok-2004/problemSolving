/*
Print Anagrams Together
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (const auto &str : arr)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].emplace_back(str);
        }

        for (auto &group : mp)
        {
            res.emplace_back(move(group.second));
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    vector<vector<string>> result = s.anagrams(arr);

    for (auto group : result)
    {
        for (string word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}