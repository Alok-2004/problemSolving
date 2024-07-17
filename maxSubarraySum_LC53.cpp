#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int res = INT_MIN;
        int sum = 0;
        for( auto ele : nums){
            sum += ele;
            res = max(sum, res);
            if(sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};
