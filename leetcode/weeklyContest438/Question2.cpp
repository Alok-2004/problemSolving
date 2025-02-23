/*
Q2. Maximum Sum With at Most K Elements
You are given a 2D integer matrix grid of size n x m, an integer array limits of length n, and an integer k. The task is to find the maximum sum of at most k elements from the matrix grid such that:

The number of elements taken from the ith row of grid does not exceed limits[i].

Return the maximum sum.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> sortedGrid = grid;
        
        for (int i = 0; i < n; i++) {
            sort(sortedGrid[i].begin(), sortedGrid[i].end(), greater<int>());
        }
        
        priority_queue<pair<int, int>> pq;
        
        vector<int> rowIndex(n, 0); 
        vector<int> used(n, 0);  
        
        for (int i = 0; i < n; i++) {
            if (limits[i] > 0) { 
                pq.push({sortedGrid[i][0], i});
                rowIndex[i] = 1;
            }
        }
        
        long long sum = 0;
        int elementsUsed = 0;
        
        while (!pq.empty() && elementsUsed < k) {
            int val = pq.top().first;
            int row = pq.top().second;
            pq.pop();
            
            sum += val;
            elementsUsed++;
            used[row]++;
            
            if (used[row] < limits[row] && rowIndex[row] < m) {
                pq.push({sortedGrid[row][rowIndex[row]], row});
                rowIndex[row]++;
            }
        }
        
        return sum;
    }
};

int main(){
	
}
