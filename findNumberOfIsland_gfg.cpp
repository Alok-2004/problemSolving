/*
Find the number of islands
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	
  	void dfs(int i , int j , vector<vector<char>>&grid , char color){
  		int n = grid.size();
  		int m = grid[0].size();
  		
  		if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != color) return;
  		grid[i][j] = '0';
  		dfs(i-1 , j , grid , color);
  		dfs(i , j-1 , grid , color);
  		dfs(i+1 , j , grid , color);
  		dfs(i , j+1 , grid , color);
  		dfs(i-1 , j-1 , grid , color);
  		dfs(i+1 , j+1 , grid , color);
  		dfs(i-1 , j+1 , grid , color);
  		dfs(i+1 , j-1 , grid , color);
  		
  		return;
	}
	
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for(int i = 0 ; i < grid.size() ; i++){
        	for(int j = 0 ; j < grid[0].size() ; j++){
        		if(grid[i][j] != '0') {
        			res++;
        			dfs(i, j, grid, grid[i][j]);
				}
			}
		}
		
		return res;
    }
};


int main(){
	
}
