/*
Modify the Array
Given an array arr. Return the modified array in such a way that if the current and 
next numbers are valid numbers and are equal then double the current number value and 
replace the next number with 0. After the modification, rearrange the array such that 
all 0's are shifted to the end.

Note:

Assume ‘0’ as the invalid number and all others as a valid number.
The sequence of the valid numbers is present in the same order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] == arr[i-1] and arr[i] != 0){
                arr[i-1] = 2*arr[i-1];
                arr[i] = 0;
            }
        }
        
        int k = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] != 0){
                arr[k] = arr[i];
                k++;
            }
        }
        
        for(int i = k ; i < arr.size() ; i++){
            arr[i] = 0;
        }
        
        return arr;
    }
};

int main(){
	
}
