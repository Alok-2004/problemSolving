/*
2661. First Completely Painted Row or Column
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                pair<int, int> p = make_pair( i , j );
                mp[mat[i][j]] = p;
            }   
        }
        vector<int>row(mat.size() , mat[0].size());
        vector<int>col(mat[0].size() , mat.size());

        for(int i = 0 ; i < arr.size() ; i++){
            row[mp[arr[i]].first]--;
            col[mp[arr[i]].second]--;
            if(col[mp[arr[i]].second] == 0 or row[mp[arr[i]].first] == 0) return i;
        }
        return -1;
    }
};

int main(){
	
}
