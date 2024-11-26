/*
2257. Count Unguarded Cells in the Grid
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls 
where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless 
obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.
*/
#include<bits/stdc++.h>
usiing namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (auto val : w) vis[val[0]][val[1]] = 2;
        for (auto val : g) vis[val[0]][val[1]] = 3;
        
        for (auto val : g) {
            int row = val[0], col = val[1];
            for (int i = row + 1; i < m; i++) {
                if (vis[i][col] == 2 || vis[i][col] == 3) break;
                vis[i][col] = 1;
            }
            for (int i = row - 1; i >= 0; i--) {
                if (vis[i][col] == 2 || vis[i][col] == 3) break;
                vis[i][col] = 1;
            }
            for (int i = col + 1; i < n; i++) {
                if (vis[row][i] == 2 || vis[row][i] == 3) break;
                vis[row][i] = 1;
            }
            for (int i = col - 1; i >= 0; i--) {
                if (vis[row][i] == 2 || vis[row][i] == 3) break;
                vis[row][i] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) res++;
            }
        }
        return res;
    }
};

int main(){
	
}
