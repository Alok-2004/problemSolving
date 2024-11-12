/*
221. Maximal Square
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size() , vector<int>(matrix[0].size() , -1));
        int res = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            dp[i][0] = matrix[i][0] - '0';
            res = max(dp[i][0] , res);
        }

        for(int j = 0 ; j < matrix[0].size() ; j++){
            dp[0][j] = matrix[0][j] - '0';
            res = max(dp[0][j] , res);
        }

        for(int i = 1 ; i < matrix.size() ; i++){
            for(int j = 1 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]});
                }
                res = max(dp[i][j] , res);
            }
        }

        return res * res;
    }
};

int main(){
	
}
