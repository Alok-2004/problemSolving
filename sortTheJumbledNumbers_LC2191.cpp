/*
2191. Sort the Jumbled Numbers
You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
*/

#include<bits/stdc++.h>
usig namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> temp;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int curr = 0;
            int pow = 1;

            if (x == 0) {
                curr = mapping[0];
            } else {
                while (x > 0) {
                    int j = x % 10;
                    curr += mapping[j] * pow;
                    x = x / 10;
                    pow *= 10;
                }
            }
            
            temp.push_back({curr, i}); 
        }

        sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        vector<int> result(nums.size());
        for (int i = 0; i < temp.size(); i++) {
            result[i] = nums[temp[i].second];
        }

        return result;
    }
};

