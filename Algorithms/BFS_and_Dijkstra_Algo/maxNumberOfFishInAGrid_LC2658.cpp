/*
2658. Maximum Number of Fish in a Grid
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 
*/

#inclde<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:

    int solve(vector<vector<int>>& grid , int row , int col , set<pair<int , int>>&st){
        int res = 0;
        vector<vector<int>>dir = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0}};
        queue<pair<int , int>>q;
        q.push({row, col});
        while(!q.empty()){

            auto idx  = q.front();
            q.pop();

            for(auto ele : dir){
                int i = idx.first + ele[0];
                int j = idx.second + ele[1];

                if( !st.count({i , j}) and i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() && grid[i][j] > 0){
                    st.insert({ i , j });
                    q.push({i , j});
                    res += grid[i][j];
                }
            }
        }

        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        set<pair<int , int>>st;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                pair<int, int> p = {i, j};
                if( grid[i][j] > 0 and !st.count({i , j}) ){
                    st.insert({i , j});
                    int temp = grid[i][j] +  solve(grid , i , j , st);
                    res = max(res, temp);
                }
            }
        }
        return res;
    }
};
*/


// Better to use visited array instead of a visited set
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        int res = grid[row][col];
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : dir) {
                int i = r + d[0];
				int j = c + d[1];
                if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !visited[i][j] && grid[i][j] > 0) {
                    visited[i][j] = true;
                    q.push({i, j});
                    res += grid[i][j];
                }
            }
        }

        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    res = max(res, solve(grid, i, j, visited));
                }
            }
        }

        return res;
    }
};

int main(){
	
}
