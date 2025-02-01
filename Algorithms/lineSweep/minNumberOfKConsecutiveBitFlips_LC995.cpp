/*
995. Minimum Number of K Consecutive Bit Flips
You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

A subarray is a contiguous part of an array.


*/

#include<bits/stdc++.h>
using namespace std;


// there an other approach of line sweep where we just use a single variable and increase it wherever needed but when need to decrese decrease in original variable
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int>temp(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(i == 0 && nums[i] == 0) {
                if(i + k > n) return -1;
                count++;
                temp[i] += 1;
                if(i + k < n) temp[i + k] -= 1;
            }
            
            if(i > 0) {
                temp[i] += temp[i-1];
                if((nums[i] + temp[i]) % 2 != 1) {
                    if(i + k > n) return -1;
                    count++;
                    temp[i] += 1;
                    if(i + k < n) temp[i + k] -= 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if((nums[i] + temp[i]) % 2 == 0) {
                return -1;
            }
        }
        
        return count;
    }
};

int main(){
	
}
