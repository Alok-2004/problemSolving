#include <bits/stdc++.h>
using namespace std;
// This method is not efficient and not fessible
/*
class Solution {
public:
    set<pair<int, int>> unS;

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Row-wise counting
        int rX = 0, rY = 0;
         rX = 0; rY = 0; // Reset counters for each row
        for (int i = 0; i < m; i++) {
            int X = 0, Y = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X'){
                 rX++;

                }
                if (grid[i][j] == 'Y') rY++;
                cout << "Row " << i << ", Col " << j <<" : rX=" << rX << ", rY=" << rY << endl;
                if (rX > 0 && rY > 0 && rX == rY && && X == Y){ 
                    unS.insert({i, j});
                    cout << "Inserted: " << i << " " << j << endl;
                }
            }
        }

        cout<<endl;    

        // Column-wise counting
        int cX = 0, cY = 0;
        cX = 0; cY = 0; // Reset counters for each column
        for (int j = 0; j < n; j++) {
            int X = 0, Y = 0;
            for (int i = 0; i < m; i++) {    
                if (grid[i][j] == 'X') cX++;
                if (grid[i][j] == 'Y') cY++;
                cout << "Col " << j << ", Row " << i <<": cX=" << cX << ", cY=" << cY << endl;
                if (cX > 0 && cY > 0 && cX == cY && X == Y){
                    unS.insert({i, j});
                    cout << "Inserted: " << i << " " << j << endl;
                }
            }
        }

        return unS.size();
    }
};
*/

int main() {
    vector<vector<char>> grid = { {'X', '.'}, {'Y', 'Y'} };
    cout << "Printing all the element\n";
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution sol;
    int res = sol.numberOfSubmatrices(grid);

    cout << "Number of submatrices: " << res << endl;

    // Print all values in the set
    for (const auto& pair : sol.unS) {
        cout << "{" << pair.first << ", " << pair.second << "}" << endl;
    }

    return 0;
}
