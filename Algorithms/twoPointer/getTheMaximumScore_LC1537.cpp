/*
1537. Get the Maximum Score
You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
The score is defined as the sum of unique values in a valid path.

Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

// More Complex but solvable
/*
class Solution{
public:
	int maxSum(vector<int>&nums1 , vector<int>&nums2){
		const int MOD = 1e9 + 7;
		int n = nums1.size(), m = nums2.size();
        
		vector<long long> suffix1(n + 1, 0), suffix2(m + 1, 0);
		
		for (int i = n - 1; i >= 0; --i) {
            suffix1[i] = nums1[i] + suffix1[i + 1];
        }
        for (int j = m - 1; j >= 0; --j) {
            suffix2[j] = nums2[j] + suffix2[j + 1];
        }
		
		int i = 0, j = 0;
        long long result = 0;
		bool flag = true; // True means nums1 and false means nums2
		
		while(i < n and j < m){
			if(nums1[i] == nums2[j]){
				if(suffix1[i] > suffix2[j]) flag = true;
				else flag = false;
			}
			if(flag){
				res += nums[i];
				i++; 
			}else{
				res += nums[j];
				j++;
			}
		}
		
		int res = result % MOD;
		return res;	
	}	
};
*/

// Better Approach

int maxSum(vector<int>& nums1, std::vector<int>& nums2) {
    const int MOD = 1'000'000'007;
    long sum1 = 0, sum2 = 0, result = 0;
    int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            sum1 += nums1[i++];
        } else if (nums1[i] > nums2[j]) {
            sum2 += nums2[j++];
        } else {
            result += max(sum1, sum2) + nums1[i];
            sum1 = sum2 = 0;
            ++i;
            ++j;
        }
    }

    while (i < n1) {
        sum1 += nums1[i++];
    }

    while (j < n2) {
        sum2 += nums2[j++];
    }

    result += max(sum1, sum2);
    return result % MOD;
}

int main(){
	
}
