/*
416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/

#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSum(int target, vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }

    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % 2 != 0) return false;
        return subsetSum(sum / 2, nums);
    }
};

int main(){
	
}
