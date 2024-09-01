/*
2022. Convert 1D Array Into 2D Array
You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. 
You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, 
the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if(m * n != o.size()) return {};
        int k = 0;
        vector<vector<int>>res(m , vector<int>(n));
        for(int i = 0; i < m && k < o.size(); i++){
            for(int j = 0; j < n && k < o.size(); j++ ){
                res[i][j] = o[k];
                k++;
            }
        }
        return res;
    }
};

int main(){
	
}
