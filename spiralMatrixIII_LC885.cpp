/*
885. Spiral Matrix III
You start at the cell (rStart, cStart) of an rows x cols grid facing east. 
The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. 
Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). 
Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.
*/

class Solution {
public:
    static vector<vector<int>> spiralMatrixIII(int rows, int cols, int r0, int c0) {
        vector<vector<int>> ans(rows*cols);
        ans[0]={{r0, c0}};
        int layer=max({rows-r0, cols-c0, r0+1, c0+1});
        vector<array<deque<char>, 4>> ring(layer);//push_back or push_front
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int d=max(abs(i-r0), abs(j-c0));
                int region;
                if (i==r0-d) ring[d][3].push_back(j);//rightward
                else if (i-r0==d) ring[d][1].push_front(j);//leftward
                else if (j-c0==-d) ring[d][2].push_front(i);//upward
                else ring[d][0].push_back(i);//downward
            }
        }
        int idx=1;
        for(int m=1; m<layer; m++){
            auto R=ring[m];
            int sz=R[0].size();
            for(int a=0; a<sz; a++) ans[idx++]={{R[0][a], m+c0}};
            sz=R[1].size();
            for(int a=0; a<sz; a++) ans[idx++]={{m+r0, R[1][a]}};
            sz=R[2].size();
            for(int a=0; a<sz; a++) ans[idx++]={{R[2][a], c0-m}};
            sz=R[3].size();
            for(int a=0; a<sz; a++) ans[idx++]={{ r0-m, R[3][a]}};
        }
        return ans;
    }
};
