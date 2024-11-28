/*
2290. Minimum Obstacle Removal to Reach Corner
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
*/

#include<bit/stdc++.h>
using namespace std;


//Will enter in loop
/*
class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid, set<pair<int, int>> visited) {
        if (dp[row][col] != -1) return dp[row][col];
        
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int curr = INT_MAX;

        for (auto& x : dir) {
            int i = row + x[0];
            int j = col + x[1];
            if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || visited.count({i, j})) continue;
            
            visited.insert({row, col});
            
            curr = min(curr, solve(i, j, dp, grid, visited));
            
            visited.erase({row, col});
        }

        dp[row][col] = grid[row][col] + curr;
        return dp[row][col];
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = 0;
        set<pair<int, int>> visited;
        visited.insert({0, 0});

        return solve(0, 0, dp, grid, visited);
    }
};
*/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (auto& d : dir) {
                int i = row + d[0];
                int j = col + d[1];

                if (i >= 0 && i < m && j >= 0 && j < n) {
                    int newCost = dp[row][col] + grid[i][j];

                    if (newCost < dp[i][j]) {
                        dp[i][j] = newCost;

                        if (grid[i][j] == 0)
                            dq.push_front({i, j});
                        else
                            dq.push_back({i, j});
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main(){
	
}
