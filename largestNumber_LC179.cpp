/*
179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    static bool cmp(int a,int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    string largestNumber(vector<int>& nums){
        sort(nums.begin(),nums.end(),cmp);

        if(nums[0] == 0) return "0";

        string ans;
        for(int n:nums) ans += to_string(n);

        return ans;
    }
};
