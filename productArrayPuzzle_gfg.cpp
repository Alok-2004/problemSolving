/*
Product array puzzle
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].
*/

class Solution{
public:
 vector<long long int> productExceptSelf(vector<long long int>& nums) {
    int n = nums.size();
    vector<long long int> prefix(n, 1), suffix(n, 1), result(n);

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}
};

