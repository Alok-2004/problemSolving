/*
Minimize the Heights I
Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
Note: Assume that height of the tower can be negative.
A slight modification of the problem can be found here. 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        if (n == 1) return 0;
        
        sort(arr, arr + n);
        
        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        
        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i + 1] - k);
            int max_height = max(largest, arr[i] + k);
            ans = min(ans, max_height - min_height);
        }
        
        return ans;
    }
};

