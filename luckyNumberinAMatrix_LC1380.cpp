/*
1380. Lucky Numbers in a Matrix

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<int>res;
        int c = m[0].size();
        int r = m.size();

        unordered_set<int>mn;
        for(int i = 0; i < r; i++){
            int curr = *min_element(m[i].begin(), m[i].end());
            mn.insert(curr);
        }
        for(int j = 0; j < c; j++){
            int temp = INT_MIN;
            for(int i = 0; i < r; i++){
                temp = max(temp, m[i][j]);
            }
            if(mn.find(temp) != mn.end()){
                res.push_back(temp);
            }
        }
        return res;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main{

}
