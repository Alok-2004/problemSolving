/*
2017. Grid Game
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. 
Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.
*/

#include<bits/stdc+++.h>
using namespace std;


// Robot two can either take top right or bottom left not both
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemain = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemain = 0;
        long long minimizedRobot2 = LONG_LONG_MAX;

        for(int i = 0 ; i < grid[0].size() ; i++){
            firstRowRemain -= grid[0][i];
            long long mx = max(firstRowRemain , secondRowRemain);
            minimizedRobot2 = min(minimizedRobot2 , mx);
            secondRowRemain += grid[1][i];
        }

        return minimizedRobot2;
    }
};

int main(){
	
}
