/*
812. Largest Triangle Areas
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. 
Answers within 10-5 of the actual answer will be accepted.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double area = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) +
                                             points[j][0] * (points[k][1] - points[i][1]) +
                                             points[k][0] * (points[i][1] - points[j][1]));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
