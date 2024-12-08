// 1760. Minimum Limit of Balls in a Bag

/*
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        const int n=nums.size();
        int l=1, r=*max_element(nums.begin(), nums.end()), m;
        while(l<r){
            m=l+(r-l)/2;
            long long cnt=0;
            for(int j=0; j<n && cnt<=k; j++)
                cnt+=(nums[j]-1)/m;
            if(cnt<=k) r=m;
            else l=m+1;
        }
        return r;
    }
};

int main(){
	
}