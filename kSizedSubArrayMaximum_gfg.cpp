#include<bits/stdc++.h>

using namespace std;

//Optimized brute force
/*
class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> temp(arr, arr + n);
        vector<int> res;
        
        int mx = INT_MIN;
        int mx_idx = -1;
        for(int i = 0; i < k; ++i) {
            if(arr[i] > mx) {
                mx = arr[i];
                mx_idx = i;
            }
        }
        res.push_back(mx);
        
        for(int i = 1; i <= n - k; i++){
            if(mx_idx >= i && mx <= i+k-1){
                if(arr[i + k - 1] > mx) {
                    mx = arr[i + k - 1];
                    mx_idx = i + k - 1;
                }
            }
            else{ 
                mx = arr[i];
                mx_idx = i;
                for(int j = i + 1; j < i + k; ++j) {
                    if(arr[j] > mx) {
                        mx = arr[j];
                        mx_idx = j;
                    }
                }
            }
            res.push_back(mx);
        }
       return res;
    }
};
*/


// using Queue
// Optimized
class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k){
      vector<int> res;
      deque<int>dq;
      for(int i = 0; i < n; i++){
      	if(!dq.empty() && dq.front() == i - k)  
		  dq.pop_front();
      	while(!dq.empty() && arr[dq.back()] <= arr[i])
      	  dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)   
    	  res.push_back(arr[dq.front()]);
        }
        return res;
    }
};
