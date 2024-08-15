/*
Given an amount and the denominations of coins available, determine how many ways change can be made for amount. There is a limitless supply of each coin type.

Example


There are  ways to make change for : , , and .

Function Description

Complete the getWays function in the editor below.

getWays has the following parameter(s):

int n: the amount to make change for
int c[m]: the available coin denominations
*/

#include<bits/stdc++.h>
using namespace std;

//Issue -  All Possibe permutaions are taken into consideration 
/*
long helper(int n , vector<long> &c , vector<long>&dp , int idx){
    if(dp[n] != -1) return dp[n];
    dp[n] = 0;
    for(size_t i = idx; i < c.size() ; i++){
        if( n-c[i] >= 0 ){
            dp[n] += helper(n-c[i] , c , dp , i+1);
        } 
    }
    cout<<n<<" "<<dp[n]<<endl;
    return dp[n];
}

long getWays(int n, vector<long> c) {
    vector<long>dp(n+1 , -1);
    dp[0] = 1;
    helper(n, c,dp , 0);
    return dp[n];
}
*/

//State of dp depends on the idx of coins vector and money left to be targeted
long countWays(int n, const vector<long>& c, vector<vector<long>>& memo, int idx) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (idx >= c.size()) return 0;

    if (memo[n][idx] != -1) return memo[n][idx];

    long exclude = countWays(n, c, memo, idx + 1);
    long include = 0;
    if (n - c[idx] >= 0) {
        include = countWays(n - c[idx], c, memo, idx);
    }

    memo[n][idx] = exclude + include;
    return memo[n][idx];
}

long getWays(int n, vector<long> c) {
    vector<vector<long>> memo(n + 1, vector<long>(c.size(), -1));
    return countWays(n, c, memo, 0);
}
