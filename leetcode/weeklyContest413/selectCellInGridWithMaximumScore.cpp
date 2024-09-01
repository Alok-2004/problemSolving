/*
Q3. Select Cells in Grid With Maximum Score
You are given a 2D matrix grid consisting of positive integers.

You have to select one or more cells from the matrix such that the following conditions are satisfied:

No two selected cells are in the same row of the matrix.
The values in the set of selected cells are unique.
Your score will be the sum of the values of the selected cells.

Return the maximum score you can achieve. 
*/
class Solution {
public:
    int solve(int i, vector<vector<int>>& grid, unordered_set<int> &uS, vector<vector<int>>& dp) {
        if (i > grid.size() - 1) return 0;

        if ( dp[i][uS.size()] != -1 ) return dp[i][uS.size()];

        int res = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            int value = grid[i][j];
            cout<<grid[i][j]<<endl;
            if (uS.find(value) == uS.end()) {
                uS.insert(value);
                res = max(res, value + solve(i + 1, grid, uS, dp));
                uS.erase(value);
            }
        }

        dp[i][uS.size()] = res;
        return res;
    }

    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n + 1, -1));
        unordered_set<int> uS;
        return solve(0, grid, uS, dp);
    }
};

