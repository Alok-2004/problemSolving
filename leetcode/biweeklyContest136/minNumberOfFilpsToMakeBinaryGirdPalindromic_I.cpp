/*
Q2. Minimum Number of Flips to Make Binary Grid Palindromic I
You are given an m x n binary matrix grid.
A row or column is considered palindromic if its values read the same forward and backward.
You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int nR = grid.size();
        int nC = grid[0].size();

        // Checking for rows
        int rR = 0;
        for(auto arr : grid) {
            int i = 0;
            int j = arr.size() - 1;
            while(i < j) {
                if(arr[i] != arr[j]) {
                    rR++;
                }
                i++;
                j--;
            }
        }

        // Now checking columns
        int cR = 0;
        for(int j = 0; j < nC; j++) {
            int i = 0;
            int k = nR - 1;
            while(i < k) {
                if(grid[i][j] != grid[k][j]) {
                    cR++;
                }
                i++;
                k--;
            }
        }
        return min(cR , rR);
    }
};

