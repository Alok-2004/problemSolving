/*
Wasn't able to solve

100365. Minimum Array Changes to Make Differences Equal
You are given an integer array nums of size n where n is even, and an integer k.

You can perform some changes on the array, where in one change you can replace any element in the array with any integer in the range from 0 to k.

You need to perform some changes (possibly none) such that the final array satisfies the following condition:

There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).
Return the minimum number of changes required to satisfy the above condition.
*/

#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int minChanges(vector<int>& nums, int k) {
//         unordered_set<int>uS;
        
//         int n = nums.size() - 1;
        
//         for(int i = 0; i <= (n / 2) - 1; i++){
//             int def = abs( nums[i] - nums[ n - i] );
//             cout<<def<<endl;
//             uS.insert(def);
//         }
        
//         int res = uS.size() - 1;
        
//         return res;
//     }
// };


int main(){
	vector<int>nums = {0,1,2,3,3,6,5,4};
	int k = 6;
	Solution s;
	cout<<s.minChanges(nums, k);
}
