/*
1886. Determine Whether Matrix Can Be Obtained By Rotation
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true; // Check if already equal
        
        int r90 = 0, r180 = 0, r270 = 0;
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == target[j][n - i - 1]) r90++;
                if (mat[i][j] == target[n - i - 1][n - j - 1]) r180++;
                if (mat[i][j] == target[n - j - 1][i]) r270++;
            }
        }
        
        int total = n * n;
        return r90 == total || r180 == total || r270 == total;
    }
};

int main(){
	
}
