/*
1508. Range Sum of Sorted Subarray Sums
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and 
then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
Since the answer can be a huge number return it modulo 109 + 7.
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>temp;
        for(int i = 0 ; i < nums.size() ; i++){
            int sum = 0;
            for( int j = i ; j < nums.size() ; j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin() , temp.end());
        int res = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            res = (res + temp[i]) % mod;
        }
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
