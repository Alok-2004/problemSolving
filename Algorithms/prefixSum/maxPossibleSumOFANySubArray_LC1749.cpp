/*
1749. Maximum Absolute Sum of Any Subarray
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxP = 0;
        int temp = 0;
        for(int i = 0; i < nums.size() ; i++){
            temp += nums[i];
            maxP = max(temp , maxP);
            if(temp <= 0){
                temp = 0;
            }
        }

        temp  = 0;

        int minP = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            temp += nums[i];
            minP = min(temp , minP);
            if(temp >= 0){
                temp = 0;
            }
        }

        return max(abs(maxP) , abs(minP));
    }
};

int main(){
	
}
