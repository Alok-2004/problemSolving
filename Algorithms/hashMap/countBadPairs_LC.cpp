/*
2364. Count Number of Bad Pairs
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> mp;
            long long count = 0, n = nums.size();
    
            for (int i = 0; i < n; i++) {
                count += mp[nums[i] - i];
                mp[nums[i] - i]++;
            }
    
            return n * (n - 1) / 2 - count;
        }
    };
    

int main(){

}