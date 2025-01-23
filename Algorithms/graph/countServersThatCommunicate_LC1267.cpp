/*
1267. Count Servers that Communicate
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) { 
                    indexColCount[col] += 1;
                    indexRowCount[row] += 1;
                }
            }
        }

        int res = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 and (indexColCount[j] > 1 or indexRowCount[i] > 1)){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
	
}
