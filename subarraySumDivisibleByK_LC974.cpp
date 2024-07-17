/*
974. Subarray Sums Divisible by K
Medium
Topics
Companies
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0]++;
        int res = 0; 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            cout << rem << endl;
            if(m.find(rem) != m.end()) {
                res += m[rem];
                m[rem]++;
            } else {
                m[rem]++;
            }
        }
        return res;    
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 9};
    int k = 3;
    cout << "Result: " << sol.subarraysDivByK(nums, k) << endl;
    return 0;
}

