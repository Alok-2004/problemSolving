#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> arr){
	int n = arr.size();
	vector<int> res(n, -1);
	
	stack<int>st;
	for(int i = n-1; i>=0; i--){
		while(!st.empty() && st.top() <= arr[i]){
			cout<<st.top()<<" ";
			st.pop();
		}
		if(!st.empty()) res[i] = st.top();
		st.push(arr[i]);
	}
	cout<<endl;
	
	return res;	
}

int main(){
	vector<int> arr = {3, 4, 2, 6, 8, 7, 10};
	vector<int> res = nge(arr);
	for(auto ele : res)  cout<<ele<<" ";
}
