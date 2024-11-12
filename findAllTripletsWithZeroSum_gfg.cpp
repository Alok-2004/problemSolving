/*
Find All Triplets with Zero Sum
Given an array arr[], find all possible indices [i, j, k] of triplets [arr[i], arr[j], arr[k]] in the array whose sum is equal to zero. 
Return indices of triplets in any order and all the returned triplets indices should also be internally sorted, 
i.e., for any triplet indices [i, j, k], the condition i < j < k should hold.

Note: Try to solve this using the O(n2) approach.
*/

#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>>ans;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                int sum = arr[i] + arr[j];
                mp[sum].push_back({i, j});
            }
        }
        for(int k=0;k<arr.size();k++){
            int target=-arr[k];
            auto it = mp.find(target);
            if(it!=mp.end()){
                for (const auto& pair : it->second) {
                int i=pair.first;
                int j=pair.second;
                if(i<j && j<k){
                    ans.push_back({i , j , k});
                }
                }
            }
        }
        return ans;
    }
};

int main(){
	
}
