/*
453. Minimum Moves to Equal Array Elements
Given an integer array nums of size n, return the minimum number of moves required to 
make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int m=INT_MAX;
		for(int n:nums) m = min(m,n);
		int ans=0;
		for(int n:nums) ans+=n-m;
		return ans;
	}
};

int main(){
	
}
