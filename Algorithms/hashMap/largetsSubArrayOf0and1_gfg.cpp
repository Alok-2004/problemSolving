/*
Largest subarray of 0's and 1's
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.
*/

#inlude<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int curr = 0;
        int res = 0;
        unordered_map<int , int>mp;
        for(int i = 0; i < arr.size() ; i++){
            curr += (arr[i] == 0) ? -1 : 1;
            if(curr == 0) res = i+1;
            if(mp.count(curr)){
                res = max(res , i - mp[curr]);
            }
            else mp[curr] = i;
        }
        return res;
    }
};

int main(){
	
}
