/*
1975. Maximum Matrix Sum
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. 
Return the maximum sum of the matrix's elements using the operation mentioned above.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int small = INT_MAX;
        long long res = 0;
        for(int i = 0; i < matrix.size() ; i++){
            for(auto ele : matrix[i]){
                small = min(small , abs(ele));
                res += abs(ele);
                if(ele < 0) count++;
            }
        }

        if(count % 2 == 0) return res;
        else return res - small * 2;
    }
};

int main(){
	
}
