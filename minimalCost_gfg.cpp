/*
Minimal Cost
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. 
Find the minimum possible total cost incurred before the Geek reaches the last stone.
*/

#include<bits/stdc++.h>
uisng namespace std;

class Solution {
  public:
    int solve(vector<int>& arr, int k, vector<int>& dp, int n) {
        if (n == arr.size()-1) return 0;
        if (dp[n] != -1) return dp[n];
        
        int mn = INT_MAX;
        
        for (int i = 1; i < k; i++) {
            if (n + i < arr.size()) {
                mn = min(mn, abs(arr[n] - arr[n + i]) + solve(arr, k, dp, n + i));
            }
        }
        
        dp[n] = mn;
        return dp[n];
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, k, dp, 0);
    }
};

int main(){
	
}


