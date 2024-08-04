/*
Q1. Design Neighbor Sum Service
You are given a n x n 2D array grid containing distinct elements in the range [0, n2 - 1].
Implement the neighborSum class:
neighborSum(int [][]grid) initializes the object.
int adjacentSum(int value) returns the sum of elements which are adjacent neighbors of value, 
that is either to the top, left, right, or bottom of value in grid.
int diagonalSum(int value) returns the sum of elements which are diagonal neighbors of value, 
that is either to the top-left, top-right, bottom-left, or bottom-right of value in grid.
*/
#include <vector>
using namespace std;

class neighborSum {
public:
    vector<vector<int>> grid;

    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }

    int adjacentSum(int value) {
        int nC = grid[0].size();
        int nR = grid.size();
        int xC = -1;
        int yC = -1;

        for(int i = 0; i < nR; i++) {
            for(int j = 0; j < nC; j++) {
                if(grid[i][j] == value) {
                    xC = i;
                    yC = j;
                    break;
                }
            }
            if(xC != -1) break;
        }

        int res = 0;
        if(xC != 0) res += grid[xC - 1][yC];
        if(xC != (nR - 1)) res += grid[xC + 1][yC];
        if(yC != 0) res += grid[xC][yC - 1];
        if(yC != (nC - 1)) res += grid[xC][yC + 1];

        return res;
    }

    int diagonalSum(int value) {
        int nC = grid[0].size();
        int nR = grid.size();
        int xC = -1;
        int yC = -1;

        for(int i = 0; i < nR; i++) {
            for(int j = 0; j < nC; j++) {
                if(grid[i][j] == value) {
                    xC = i;
                    yC = j;
                    break;
                }
            }
            if(xC != -1) break;
        }

        int res = 0;
        if(xC != 0 && yC != 0) res += grid[xC - 1][yC - 1];
        if(xC != (nR - 1) && yC != (nC - 1)) res += grid[xC + 1][yC + 1];
        if(xC != 0 && yC != (nC - 1)) res += grid[xC - 1][yC + 1];
        if(xC != (nR - 1) && yC != 0) res += grid[xC + 1][yC - 1];

        return res;
    }
};

