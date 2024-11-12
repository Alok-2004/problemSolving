/*
962. Maximum Width Ramp
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. 
The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. 
If there is no ramp in nums, return 0.
*/

#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int> >temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back({nums[i] , i});
        }

        sort(temp.begin() , temp.end(),  [](pair<int,int>& a, pair<int,int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        int result = 0;
        int mn = temp[0].second;
        stack<int>st;
        st.push(temp[0].second);
        for(int i = 1 ; i < temp.size() ; i++){
            if(st.top() <= temp[i].second ){
                result = max(result , temp[i].second - mn);
                st.push(temp[i].second);
            }else{
                while(!st.empty() and st.top() > temp[i].second){
                    st.pop();
                }
                st.push(temp[i].second);
                mn = min(mn , st.top());
            }
        }

        return result;
    }
};
*/
//Two pointers Approach
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       int n = nums.size();
	   vector<int>nge(n,INT_MIN);
	   nge[n-1] = nums[n-1];
	   for(int i = n-2; i >= 0; i--){
	   		nge[i] = max(nge[i+1], nums[i]);
	   }
	   
	   int ramp = 0;
	   int i = 0;
	   int j = 0;
	   while(j < n){
	   		while(i < j and nums[i] > nge[j]){
	   			i++;	
			}
			ramp = max(ramp , j-i);
			j++;
	   }
	   
	   return ramp;  
    }
};

int main(){
	
}
