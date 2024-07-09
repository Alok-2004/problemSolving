#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
//        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        long long currentTime = 0;
        long long waitingTime = 0;
        int n = cus.size();
        for(int i = 0; i<n; i++){
            if(currentTime < cus[i][0]){
                currentTime = cus[i][0];
            }
            currentTime += cus[i][1];
            waitingTime += currentTime - cus[i][0];
        }
        double res = static_cast<double>(waitingTime) / n;
        return res;
    }
};
