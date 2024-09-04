/*
The problem involves finding the minimum cost path in a grid from the top-left corner to the bottom-right corner. 
Each cell has a cost, and you can move up, down, left, or right. 
The goal is to compute the minimum path cost, considering valid moves and grid boundaries.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, bool> solve(vector<vector<pair<int, bool>>>& dp, vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) 
            return {INT_MAX, false};

        if (dp[i][j].first != -1) 
            return dp[i][j];

        int res = INT_MAX;
        bool flag = false;

        auto p = solve(dp, grid, i + 1, j);
        if (p.second) {
            res = min(res, p.first);
            flag = true;
        }

        p = solve(dp, grid, i - 1, j);
        if (p.second) {
            res = min(res, p.first);
            flag = true;
        }

        p = solve(dp, grid, i, j - 1);
        if (p.second) {
            res = min(res, p.first);
            flag = true;
        }

        p = solve(dp, grid, i, j + 1);
        if (p.second) {
            res = min(res, p.first);
            flag = true;
        }

        if (!flag) {
            dp[i][j] = {INT_MAX, false};
        } else {
            dp[i][j] = {grid[i][j] + res, true};
        }

        return dp[i][j];
    }

    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<int, bool>>> dp(n, vector<pair<int, bool>>(m, {-1, false}));

        dp[0][0] = {grid[0][0], true};

        auto p = solve(dp, grid, n - 1, m - 1);

        return p.second ? p.first : -1;
    }
};

