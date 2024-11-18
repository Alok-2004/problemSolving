//Range Update with Lazy Propagation Technique and Prefix Sum

/*
3355. Zero Array Transformation I
You are given an integer array nums of length n and a 2D array queries, 
where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array 
after processing all the queries sequentially, otherwise return false.

A subset of an array is a selection of elements (possibly none) of the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int>prefix(n+1 , 0);
        for(int i = 0 ; i < q.size() ; i++){
            prefix[q[i][0]] += -1;
            prefix[q[i][1] + 1] += 1;
        }
        bool result = true;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i != 0) prefix[i] += prefix[i-1];
            if(prefix[i] + nums[i] > 0){
                result = false;
                break;
            }  
        }   
        return result;
    }
};

int main(){
	
}
