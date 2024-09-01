/*
Maximum Difference
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element 
and the nearest right smaller element of every element in array arr. 
If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> left(vector<int> &arr){
        vector<int>res(arr.size() , 0);
        stack<int>s;
        
        s.push(arr[0]);
        for(int i = 1 ; i < arr.size(); i++){
            if( s.empty() ){
                s.push(arr[i]);
            }else{
                while(!s.empty() and s.top() >= arr[i]){
                    s.pop();
                }
                if( !s.empty() )res[i] = s.top();
                s.push(arr[i]);
            }
        }
        return res;
    }
    
    vector<int> right(vector<int> &arr){
        vector<int>res(arr.size() , 0);
        
        stack<int>s;
        s.push(arr.back());
        for(int i = arr.size() - 2 ; i >= 0; i--){
            if( s.empty() ){
                s.push(arr[i]);
            }else{
                while(!s.empty() and s.top() >= arr[i]){
                    s.pop();
                }
                if( !s.empty() )res[i] = s.top();
                s.push(arr[i]);
            }
        }
        return res;
    }
  
    int findMaxDiff(vector<int> &arr) {
        vector<int>leftSmaller = left(arr);
        vector<int>rightSmaller = right(arr);
        
        int res = INT_MIN;
        for(int i = 0; i < arr.size() ; i++){
            res = max(res , abs(leftSmaller[i] - rightSmaller[i]));
        }
        return res;
    }
};

int main(){
	
}
