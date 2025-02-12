/*
2342. Max Sum of a Pair With Equal Sum of Digits
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
*/

#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int res = -1;

        for (int i = 0; i < nums.size(); i++) {
            int sm = solve(nums[i]);
            
            if (mp.count(sm)) {
                if(nums[i] > mp[sm][1]){
                    mp[sm][0] = mp[sm][1];
                    mp[sm][1] = nums[i];
                }else{
                    mp[sm][0] = max(mp[sm][0] , nums[i]);
                }

                res = max(mp[sm][0] + mp[sm][1] , res);
            } else {
                mp[sm] = {-1, nums[i]};
            }
        }

        return res;
    }
};

int main(){
	
}
