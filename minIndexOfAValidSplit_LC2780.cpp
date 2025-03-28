/*
2780. Minimum Index of a Valid Split
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.
*/

#include<bits/stdc++.h>
using namespace std
/*
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        int n = nums.size();

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == num) count++;
            else{
                count--;
                if(count == 0){
                    num = nums[i];
                    count = 1;
                }
            }
        }

        vector<int>pre(nums.size() , 0);
        if(nums[0] == num) pre[0]++;
        for(int i = 1 ; i < n ; i++){
            pre[i] = pre[i-1];
            if(nums[i] == num) pre[i]++;
        }

        for(int i = 0; i < nums.size() ; i++){
            if(pre[i] > (i + 1) / 2 && (pre[n - 1] - pre[i]) > (n - (i + 1)) / 2) return i;
        }
        return -1;

    }
};
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num = nums[0], count = 1, n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i] == num) count++;
            else {
                count--;
                if(count == 0) {
                    num = nums[i];
                    count = 1;
                }
            }
        }

        int totalCount = 0;
        for(int x : nums) 
            if(x == num) totalCount++;

        int leftCount = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == num) leftCount++;
            int rightCount = totalCount - leftCount;

            if(leftCount > (i + 1) / 2 && rightCount > (n - (i + 1)) / 2) 
                return i;
        }
        return -1;
    }
};


int main(){
	
}
