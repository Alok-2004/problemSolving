/*
1861. Rotating the Box
You are given an m x n matrix of characters box representing a side-view of a box. 
Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
Return an n x m matrix representing the box after the rotation described above.
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size(); 
        for (int i = 0; i < row; i++) {
            int left = col - 1;
            int right = col - 1;
            while (left >= 0) {

                if (box[i][left] == '*') {
                    right = left - 1;
                } 
                
                else if (box[i][left] == '#') {
                    swap(box[i][left] , box[i][right]);
                    right--;
                }
                left--;
            }
        }

        vector<vector<char>> rotated(col, vector<char>(row));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                rotated[j][row - 1 - i] = box[i][j];
            }
        }
        return rotated;
    }
};

