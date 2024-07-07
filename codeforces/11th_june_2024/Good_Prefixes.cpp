#include<iostream>
#include<vector>

using namespace std;

int goodPrefixes(vector<long long>nums){
  int sz = nums.size();
  int ans = 0;
  if(sz == 0 && nums[0] == 0) return 1; 
  vector<long long> pre(sz, 0);
  pre[0] = nums[0];
  for(int i = 1; i< sz; i++){
  	pre[i] = nums[i] + pre[i-1];
  	if (pre[i] = 2 * pre[i-1]){
  		ans++;
	  }
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  
  vector<vector<long long>>nums(n);
  int sz;
  long long val;
  for(int i = 0; i<n; i++){
  	cin>>sz;
	for(int j = 0; j<sz; j++){
	  cin>>val;
	  nums[i].push_back(val);
	}
  }
  
  vector<int>ans(n,0);
  for(int i = 0; i<n; i++){
  	ans[i] = goodPrefixes(nums[i]);
  }
  
  cout<< "ans \n";
  for (int num : ans) {
        cout << num<< endl;
    }
}
