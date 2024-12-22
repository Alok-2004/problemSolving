/*
Search in a Row-Column sorted matrix
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int i = 0;
        int j = mat[0].size()-1;
        while(i < mat.size() and j >= 0){
            if(mat[i][j] == x){
                return true;
            }
            if(mat[i][j] < x){
                i++;
            }else if(mat[i][j] > x){
                j--;
            }
        }
        return false;
    }
};

int main(){
	
}
