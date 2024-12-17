/*
Aggressive Cows
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. 
Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool solve(int temp , vector<int> &stalls , int k ){
        bool flag = false;
        k--;
        int prev = stalls[0];
        int i = 1;
        while(i < stalls.size() and k > 0){
            if(stalls[i] - prev  >= temp){
                prev = stalls[i];
                k--;
            }
            if(k == 0){
                flag = true;
                break;
            }
            i++;
        }
        return flag;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin() , stalls.end());
        int i = 1;
        int j = stalls.back() - stalls[0];
        int ans = 0;
        while(i <= j){
            int mid = i + ((j-i) / 2);
            if(solve(mid , stalls , k)){
                ans = mid;
                i = mid + 1;
            }else{
               j = mid-1; 
            }
        }
        
        return ans;
    }
};

int main(){
	
}
