/*
Max sum path in two arrays
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. 
Find the maximum sum of a path from the beginning of any array to the end of any array. 
You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.
*/
#include<bists/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0; // arr1
        int j = 0; // arr2
        int sum1 = 0;
        int sum2 = 0;
        int res = 0;
        
        while( i < arr1.size() and j < arr2.size()){
            if(arr1[i] > arr2[j]){
                sum2 += arr2[j];
                j++;
            }
            else if(arr1[i] < arr2[j]){
                sum1 += arr1[i];
                i++;
            }
            else{
                res += max(sum1 , sum2) + arr1[i];
                sum1 = 0 , sum2 = 0;
                i++;
                j++;
            }
        }
        
        while( i < arr1.size()){
            sum1 += arr1[i];
            i++;
        }
        
        while( j < arr2.size()){
            sum2 += arr2[j];
            j++;
        }
        
        res += max(sum1 , sum2);
        return res;
        
    }
};
