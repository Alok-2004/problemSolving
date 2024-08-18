/*
1937. Maximum Number of Points with Cost
You are given an m x n integer matrix points (0-indexed). 
Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. 
Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. 
For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) 
will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
*/ 

#include<bits/stdc++.h>
using namespace std;

//Time complexity complexity of O(m * n^2)
/*
typedef long long ll;
class Solution {
public:
    ll helper(int prevColumn, int currentRow, vector<vector<ll>>& dp, vector<vector<int>>& p) {
        if (currentRow == p.size()) return 0;
        if (dp[currentRow][prevColumn] != -1) return dp[currentRow][prevColumn];

        ll res = LLONG_MIN;
        for (int i = 0; i < p[0].size(); i++) {
            ll temp = p[currentRow][i] - abs(prevColumn - i); 
            res = max(res, temp + helper(i, currentRow + 1, dp, p));
        }
        return dp[currentRow][prevColumn] = res;
    }

    ll maxPoints(vector<vector<int>>& p) {
        vector<vector<ll>> dp(p.size(), vector<ll>(p[0].size(), -1));
        ll res = LLONG_MIN;
        for (int i = 0; i < p[0].size(); i++) {
            res = max(res, p[0][i] + helper(i, 1, dp, p));
        }
        return res;
    }
};
*/


