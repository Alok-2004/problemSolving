/*
540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

#include<bits/stdc++.h>
using namespace std;

// TC - n
/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res = -1;
        for(int i = 1 ; i < nums.size() ; i += 2){
            if(nums[i] != nums[i-1]){
                res = nums[i-1];
                break;
            }   
        }

        if(res == -1) res = nums[nums.size() - 1];

        return res;
    }
};
*/

// TC - logn
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int mid = i + ((j - i)/2);

            if(mid % 2 == 0) mid--;
            if(nums[mid] == nums[mid-1])  i = mid+1;
            else j = mid - 1;
        }
        return nums[i];
    }
};
int main(){
	
}
