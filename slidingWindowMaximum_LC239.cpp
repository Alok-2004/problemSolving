#include<bits/stdc++.h>
using namespace std;

vector<int> ngi(vector<int> arr){
	int n = arr.size();
	vector<int> res(n, n);
	stack<int>st;
	for(int i = n-1; i>=0; i--){
		while(!st.empty() && arr[st.top()] <= arr[i]){
			st.pop();
		}
		if(!st.empty()) res[i] = st.top();
		st.push(i);
	}
	
	return res;	
}

vector<int> maxSlidingWindow(vector<int>&nums, int k){
	vector<int> res(nums.size() - k + 1, 0);
	vector<int>temp = ngi(nums);
	int j = 0; // it is for next greatest index
	for(int i = 0; i<=nums.size() - k; i++){
		if(j < i) j = i;
		while( temp[j] < i + k){
			j = temp[j];
		}
		res[i] = nums[j];
	}
	return res;
}

int main(){
	vector<int> arr = {3, 4, 2, 6, 8, 7, 10};
	int k = 3;
	vector<int> res = maxSlidingWindow(arr, 3);
	for(auto ele : res)  cout<<ele<<" ";
}