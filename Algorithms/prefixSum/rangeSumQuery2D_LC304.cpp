/*
304. Range Sum Query 2D - Immutable
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        mat = matrix;
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 1; i < m; ++i) {
            mat[i][0] += mat[i-1][0];
        }
        
        for (int j = 1; j < n; ++j) {
            mat[0][j] += mat[0][j-1];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = mat[row2][col2];
        int extra1 = (row1 > 0) ? mat[row1-1][col2] : 0;
        int extra2 = (col1 > 0) ? mat[row2][col1-1] : 0;
        int extra3 = (row1 > 0 && col1 > 0) ? mat[row1-1][col1-1] : 0;
        return total - extra1 - extra2 + extra3;
    }
};

int main(){
	
}
