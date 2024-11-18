// Binary Search with Line sweep

/*
3356. Zero Array Transformation II
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, 
nums becomes a Zero Array. If no such k exists, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool binarySearch(vector<int>& nums, vector<vector<int>>& q , int k){
        vector<int>pref(nums.size() + 1 , 0);
        for(int i = 0 ; i < k ; i++){
            pref[q[i][0]] -= q[i][2];
            pref[q[i][1] + 1] += q[i][2]; 
        }

        bool res = true;
        for(int i = 0 ; i < nums.size() ; i++){
            if( i != 0 ) pref[i] += pref[i-1];
            if(nums[i] + pref[i] > 0){
                res = false;
                break;
            }
        }
        return res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0;
        int r = q.size() + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if( binarySearch(nums , q , mid) ){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return l <= q.size() ? l : -1;
    }
};

int main(){
	
}
