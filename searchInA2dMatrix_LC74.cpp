/*
74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        bool flag = false;
        int r = -1;
        for(int i = 0 ; i < m.size() ; i++){
            if(m[i][m[0].size()-1] >= t){
                r = i;
                break;
            }
        }

        if(r == -1) return flag;
        
        for(int i = 0 ; i < m[0].size() ; i ++){
            if(m[r][i] == t){
                flag = true;
                break;
            }
        }
        return flag;
    }
};

int main(){
	
}
