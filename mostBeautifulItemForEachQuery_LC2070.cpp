/*
2070. Most Beautiful Item for Each Query
You are given a 2D integer array items where items[i] = [pricei, beautyi] 
denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], 
you want to determine the maximum beauty of an item whose price is less than or equal 
to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.
*/
#include<bits/stdc++.h>
using namespace std;

//TLE
/*
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        unordered_map<int , int>um; // price , beauty
        for(auto x : items){
            if(um.count(x[0])){
                um[x[0]] = max(um[x[0]] , x[1]);
            }else{
                um[x[0]] = x[1];
            }
        }
        vector<int>res(q.size() , 0);
        for(int i = 0 ; i < q.size() ; i++){
            int temp = 0;
            for(auto ele : um){
                if(q[i] >= ele.first){
                    temp = max(ele.second , temp);
                }
            }
            res[i] = temp;
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<pair<int,int>> vp;
        for(int j=0; j<m; j++){
            vp.push_back({queries[j], j});
        }
        sort(vp.begin(), vp.end());
        sort(items.begin(), items.end());

        int maxi = 0, i = 0;
        vector<int> ans(m);
        for(auto it: vp){
            int price = it.first, ind = it.second;
            while(i<n && items[i][0] <= price){
                maxi = max(maxi, items[i][1]);
                i++;
            }
            ans[ind] = maxi;
        }
        return ans;
    }
};

int main(){
	
}
