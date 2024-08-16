/*
Maximize The Cut Segments
Given an integer n denoting the Length of a line segment. 
You need to cut the line segment in such a way that 
the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
Note: if no segment can be cut then return 0.
*/
class Solution
{
    public:
    int helper(int n, vector<int>& p, vector<vector<int>>& dp, int idx) {
        if (n == 0) return 0;
        if (idx > 2) return INT_MIN;

        if (dp[n][idx] != -1) return dp[n][idx];

        int exclude = helper(n, p, dp, idx + 1);

        int include = INT_MIN;
        if (n >= p[idx]) {
            include = 1 + helper(n - p[idx], p, dp, idx);
        }

        dp[n][idx] = max(include, exclude);
        return dp[n][idx];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> p = {x, y, z};
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        
        int result = helper(n, p, dp, 0);

        return result < 0 ? 0 : result;
    }
};

