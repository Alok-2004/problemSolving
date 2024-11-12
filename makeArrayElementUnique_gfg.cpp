/*
Make array elements unique
Given an array arr[ ], your task is to find the minimum number of increment operations 
required to make all the elements of the array unique. 
i.e.- no value in the array should occur more than once. 
In one operation, a value can be incremented by 1 only.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int count = 0;
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] <= arr[i-1] ){
                count += arr[i-1] + 1 - arr[i];
                arr[i] = arr[i-1] + 1 ;
            }
        }
        
        return count;
    }
};

int main(){
	
}
