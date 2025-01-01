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
        map<string, pair<vector<string>, int>> mp;
        vector<vector<string>> res;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            string temp = arr[i];
            sort(temp.begin(), temp.end());
            if (!mp.count(temp))
            {
                vector<string> ele;
                ele.emplace_back(arr[i]);
                pair<vector<string>, int> curr = make_pair(ele, count);
                mp[temp] = curr;
                count++;
            }
            else
            {
                auto update = mp[temp];
                update.first.emplace_back(arr[i]);
                mp[temp] = update;
            }
        }

        res.resize(mp.size(), {});
        for (auto ele : mp)
        {
            int i = ele.second.second;
            res[i] = ele.second.first;
        }
        sort(res.begin(), res.end());

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