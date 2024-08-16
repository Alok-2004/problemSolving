/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include<bits/stdc++.h>
using namespace std;
// Using recursion with Memoization
/*
class Solution {
public:

    int helper(int row , int col , vector<vector<int>>&dp , vector<vector<int>>&grid){
        if(row == 0 or col == 0) return dp[row][col];
        if(row < 0 or col < 0) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];
         
        dp[row][col] = grid[row][col] + min(helper(row-1, col, dp, grid), helper(row, col-1, dp, grid));
        return dp[row][col]; 
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size() , vector<int>(grid[0].size() , -1));
        
        //Populating First Row
        dp[0][0] = grid[0][0];
        for(int i = 1 ; i < grid[0].size() ; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        //Populating First Column
        for(int i = 1; i < grid.size(); i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        return helper(grid.size() - 1, grid[0].size()-1 , dp , grid);
    }
};
*/

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};



