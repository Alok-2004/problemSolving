/*
Maximize Array Value After Rearrangement
Given an array arr of n integers. Your task is to write a program to 
find the maximum value of ?arr[i]*i, where i = 0, 1, 2,., n-1. You are allowed to rearrange the elements of the array.

Note: Since the output could be large, print the answer modulo 109+7.
*/

class Solution {
  public:
    int Maximize(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        long long result = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * i) % mod;
        }

        return result;
    }
};

