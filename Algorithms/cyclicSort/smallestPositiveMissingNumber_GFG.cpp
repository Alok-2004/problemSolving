/*
Smallest Positive Missing Number
You are given an integer array arr[]. 
Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        
        while (i < n) {
            if (arr[i] < 1 or arr[i] > n or arr[i] == arr[arr[i] - 1] or arr[i] == i+1) {
                i++;
            } else {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

int main(){
	
}
