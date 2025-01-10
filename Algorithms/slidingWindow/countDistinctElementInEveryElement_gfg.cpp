/*
Count distinct elements in every window
Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        int n = arr.size();
        
        for (int i = 0; i < k; ++i) {
            ++freq[arr[i]];
        }
        result.push_back(freq.size());
        
        for (int i = k; i < n; ++i) {
            if (--freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }
            ++freq[arr[i]];
            result.push_back(freq.size());
        }
        
        return result;
    }
};

int main(){
	
}
