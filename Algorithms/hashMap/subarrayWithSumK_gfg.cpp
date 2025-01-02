/*
Given an array arr[] consisting of N integers and an integer K, the task is to 
find the count of subarrays whose sum equals K.

Example 1:
Input: arr[] = {10, 2, -2, -20, 10}, K = -10
Output: 3
Explanation: Subarrays {2, -2, -20, 10}, {-2, -20, 10} and {-20, 10} sum to -10.

Example 2:
Input: arr[] = {9, 4, 20, 3, 10, 5}, K = 33
Output: 2
Explanation: Subarrays {20, 3, 10} and {4, 20, 3} sum to 33.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int , int>s;
        int sum = 0;
        s[0] = 1;
        int res = 0;
        for(int i = 0; i < arr.size() ; i++){
            sum += arr[i];
            int diff = sum - k;
            if(s.count(diff)){
                res += s[diff];
            }
            s[sum]++;
        }
        return res;
    }
};

int main(){

}