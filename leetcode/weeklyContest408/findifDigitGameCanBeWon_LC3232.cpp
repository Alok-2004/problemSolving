/*
LC 3232
Q1. Find if Digit Game Can Be Won
You are given an array of positive integers nums.

Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers 
or all double-digit numbers from nums, and the rest of the numbers are given to Bob. 

Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

Return true if Alice can win this game, otherwise, return false.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int pre = 0;
        int d = 0;
        for( auto x : nums){
            pre += x;
            if( x >= 10){
                d += x; 
            }
        }

        if( 2 * d == pre){
            return false;
        }else return true;
    }
};
