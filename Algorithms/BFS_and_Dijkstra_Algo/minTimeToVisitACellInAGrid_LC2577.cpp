/*
2577. Minimum Time to Visit a Cell In a Grid
You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), 
which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the 
four directions: up, down, left, and right. Each move you make takes 1 second.

Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.
*/

#include<bits/stdc++.h>
using namespace std;

//TLE
/*
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        vector<vector<int> >drcn = {{1 , 0} , {0 , 1} , {0 , -1} , {-1 , 0}};
        q.push({0, 0});
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            
            for(int i = s ; i > 0 ; i--){
                auto temp = q.front();
                q.pop();
                if(temp.first == grid.size()-1 and temp.second == grid[0].size()-1 ){
                    return res;
                }
                for(auto x : drcn){
                    int i = x[0] + temp.first;
                    int j = x[1] + temp.second;

                    if(i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and grid[i][j] <= res+1){
                        q.push({i,j});
                    }
                }
            }
            res++;
        }

        return -1;
    }
};
*/

// Using Dijkstra Algo

//time complexity : O(E + log(v)) or O(m*n + log(m*n))
//Space complexity : 

#define P pair<int, pair<int, int>>

class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
		int m = grid.size();
		int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({grid[0][0], {0, 0}}); // Start at top-left corner
        while (!pq.empty()) {
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            if (row == m - 1 && col == n - 1)
                return time;
            
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            for (auto dir: direction) {
                int r = row + dir[0];
                int c = col + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if (grid[r][c] <= time+1)
                    pq.push({time+1, {r, c}});
                else if ((grid[r][c]-time)%2==0)
                    pq.push({grid[r][c]+1, {r, c}});
                else
                    pq.push({grid[r][c], {r, c}});
            }
        }
        return -1;
    }
};

int main(){
	
}
