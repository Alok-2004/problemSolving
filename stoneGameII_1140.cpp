/*
1140. Stone Game II
Alice and Bob continue their games with piles of stones.  
There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  
The objective of the game is to end with the most stones. 
Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  
Then, we set M = max(M, X).
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //flag = 1 alice
	//Flag = 0 Bob

    int solve(int flag, int m, int i, vector<vector<vector<int>>>& dp, vector<int>& piles) {
        if (i >= piles.size()) return 0;
        if (dp[flag][i][m] != -1) return dp[flag][i][m];

        int res = (flag == 1) ? 0 : INT_MAX;
        int stones = 0;

        for (int k = 1; k <= min(2 * m, (int)piles.size() - i); k++) {
            stones += piles[i + k - 1];
            if (flag == 1) {
                res = max(res, stones + solve(0, max(m, k), i + k, dp, piles));
            } else {
                res = min(res, solve(1, max(m, k), i + k, dp, piles));
            }
        }

        return dp[flag][i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(1, 1, 0, dp, piles);
    }
};


int main(){
	
}
