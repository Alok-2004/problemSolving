/*
3394. Check if Grid can be Cut into Sections
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool horizontal(vector<vector<int>>& rec) {
        sort(rec.begin(), rec.end());

        vector<vector<int>> temp;
        auto curr = rec[0];

        for (int i = 1; i < rec.size(); i++) {
            if (curr[2] > rec[i][0]) {
                curr[2] = max(curr[2], rec[i][2]);
            } else {
                temp.push_back(curr);
                curr = rec[i];
            }
        }

        temp.push_back(curr);
        cout<<temp.size()<<endl;
        return temp.size() > 2;
    }

    bool vertical(vector<vector<int>>& rec) {
        sort(rec.begin(), rec.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<vector<int>> temp;
        auto curr = rec[0];

        for (int i = 1; i < rec.size(); i++) {
            if (curr[3] > rec[i][1]) {
                curr[3] = max(curr[3], rec[i][3]);
            } else {
                temp.push_back(curr);
                curr = rec[i];
            }
        }

        temp.push_back(curr);
        cout<<temp.size()<<endl;
        return temp.size() > 2; 
    }

    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        return horizontal(rec) || vertical(rec);
    }
};

int main(){
	
}
