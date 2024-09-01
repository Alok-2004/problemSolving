/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        res.push_back({1});
        if(n == 1){
            return res;
        }
         res.push_back({1,1});
        if(n == 2){
            return res;
        }

        for(int i = 2 ; i < n ; i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j = 1 ; j < i ; j++){
                temp.push_back( res[i-1][j-1] + res[i-1][j] );
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
	
}
