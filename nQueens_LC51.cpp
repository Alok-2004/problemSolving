/*
51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<string>> solutions;
    vector<string> board;

    bool canPlaceQueen(int row, int col, int n) {
        // Column check
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Left diagonal check
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Right diagonal check
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canPlaceQueen(row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.')); // Initialize empty board
        solve(0, n); // Start solving from row 0
        return solutions;
    }
};

int main(){
	
}
