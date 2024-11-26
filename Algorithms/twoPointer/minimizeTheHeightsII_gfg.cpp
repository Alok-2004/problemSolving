/*
Minimize the Heights II
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(n == 1) return 0;
        
        sort(arr.begin() , arr.end());
        
        int res = arr[n - 1] - arr[0];
        
        for(int i = 0 ; i < n - 1; i++){
            
            if(arr[i+1] - k < 0) continue;  
        
            int mn = min(arr[0] + k , arr[i+1] - k);
        
            int mx = max(arr[n - 1] - k , arr[i] + k);
        
            res = min(mx - mn , res);
            
        }
        
        return res;
    }
};

int main(){
	
}
