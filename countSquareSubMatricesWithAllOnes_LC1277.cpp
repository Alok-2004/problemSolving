/*
1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	int solve(int row , int col , vector<vector<int>>&dp , vector<vector<int>>& matrix){
		if(row >= dp.size() or col >= dp[0].size() or matrix[row][col] == 0 ) return 0;
		if(dp[row][col] != -1) return dp[row][col];
		vector<vector<int>>dir = {{1 , 1} , {0 , 1} , {1 , 0}};
		int ans = INT_MAX;
		
		for(auto x : dir){
			ans = min( solve(row + x[0] ,col + x[1] , dp , matrix) , ans);
		}
		
		return dp[row][col] = 1 + ans;
		 
	}
	
    int countSquares(vector<vector<int>>& matrix) {
       vector<vector<int>>dp(matrix.size() , vector<int>(matrix[0].size() , -1));
	   int result = 0;
	   for(int i = 0 ; i < matrix.size() ; i++){
	   	for(int  j = 0 ; j < matrix[0].size() ; j++){
	   		result += solve(i , j , dp , matrix);
		   }
	   }
	   return result;  
    }
};

int main(){
	
}
