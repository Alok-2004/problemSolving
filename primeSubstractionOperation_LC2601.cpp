/*
2601. Prime Subtraction Operation
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int bound = (i == 0) ? nums[i] : nums[i] - nums[i - 1];
            
            if (bound <= 0) return false;
            
            int largestPrime = 0;
            for (int j = bound - 1; j >= 2; j--) {
                if (checkPrime(j)) {
                    largestPrime = j;
                    break;
                }
            }
            
            nums[i] -= largestPrime;
        }
        
        return true;
    }
};

int main(){
	
}
