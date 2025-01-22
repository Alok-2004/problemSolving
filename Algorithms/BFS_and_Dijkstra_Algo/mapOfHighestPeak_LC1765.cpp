/*
1765. Map of Highest Peak
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>res(isWater.size() , vector<int>(isWater[0].size() , -1));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < isWater.size() ; i++){
            for(int j = 0 ; j < isWater[0].size() ; j++){
                if(isWater[i][j] == 1){
                    q.push({i , j});
                    res[i][j] = 0;
                }
            }
        }

        vector<vector<int>>dir = {{0 , 1} , {1 , 0} , {-1 , 0} , { 0 , -1}};
        while(!q.empty()){
            auto ele = q.front();
            int x = ele.first;
            int y = ele.second;
            q.pop();
            for (auto& ele : dir) {
                int nx = x + ele[0], ny = y + ele[1];

                if (nx >= 0 && nx < isWater.size() && ny >= 0 && ny < isWater[0].size() && res[nx][ny] == -1) {
                    res[nx][ny] = res[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return res;
    }
};

int main(){
	
}
