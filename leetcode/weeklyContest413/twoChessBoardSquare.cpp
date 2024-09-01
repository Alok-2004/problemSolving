/*
Q1. Check if Two Chessboard Squares Have the Same Color
You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
*/
class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int r1 = ((c1[0] - 'a') + (c1[1] - '1')) % 2;
        int r2 = ((c2[0] - 'a') + (c2[1] - '1')) % 2;
        return r1 == r2;
    }
};

