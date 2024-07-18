/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h){
		int n = h.size();
		int i = 0;
		int j = n - 1;
		int res = 0;
		while(i < j){
			int curr = min(h[i], h[j]) * (j - i);
			res = max(res, curr);
			
			if(h[i] > h[j]){
				j--;
			}else(h[i] < h[j]){
				i++;
			}else{
				i++;
				j--;
			}
		}
		
		return res
	}
};

