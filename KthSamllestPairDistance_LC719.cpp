/*
719. Find K-th Smallest Pair Distance
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, 
return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
*/

#include<bits/stdc++.h>
using namespace std;

//TC O(nlogk + n^2)
/*
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int>pq;
        vector<int>temp;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            int a = nums[i];
            for(int j = i+1; j<nums.size() ; j++){
                pq.push(abs(a-nums[j]));
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
*/

//Binary Search
//Time Complexity = O(n(logn+logd))
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0, left = 0;
            
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};

TC 


int main(){
	
}
