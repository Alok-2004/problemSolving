/*
2684. Maximum Number of Moves in a Grid
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, 
and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: 
(row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) 
such that the value of the cell you move to, should be strictly bigger than 
the value of the current cell.
Return the maximum number of moves that you can perform.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || row >= grid.size() || col >= grid[0].size()) return 0;
        if (dp[row][col] != -1) return dp[row][col];

        int localMax = 0;
        if (col+1 < grid[0].size() and row - 1 >= 0 && grid[row - 1][col + 1] > grid[row][col]) {
            localMax = max(localMax, solve(row - 1, col + 1, grid));
        }
        if (col+1 < grid[0].size() and grid[row][col + 1] > grid[row][col]) {
            localMax = max(localMax, solve(row, col + 1, grid));
        }
        if (col+1 < grid[0].size() and row + 1 < grid.size() && grid[row + 1][col + 1] > grid[row][col]) {
            localMax = max(localMax, solve(row + 1, col + 1, grid));
        }

        return dp[row][col] = 1 + localMax;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(solve(i, 0, grid), result);
        }

        return result-1 ;
    }
};

int main(){
	
}

