/*
Minimize the Heights I
Given a positive integer k and an array arr[] denoting heights of towers, you have to modify
 the height of each tower either by increasing or decreasing them by k only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n=arr.size();
        if(n==1) return 0;
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int mn=min(arr[i+1]-k,arr[0]+k);
            int mx=max(arr[n-1]-k,arr[i]+k);
            ans=min(ans,abs(mx-mn));
        }
        return ans;
    }
};

int main(){
	
}
