/*
2134. Minimum Swaps to Group All 1's Together II
A swap is defined as taking two distinct positions in an array 
and swapping the values in them.
A circular array is defined as an array where we consider the 
first element and the last element to be adjacent.
Given a binary circular array nums, 
return the minimum number of swaps required to group all 1's present in the array together at any location.
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(auto ele : nums){
            if(ele == 1) k++;
        }

        for(int i = 0; i < k-1; i++){
            nums.push_back(nums[i]);
        }

        int res = INT_MAX;
        int currentOnes = 0;

        for(int i = 0; i < k; i++){
            if(nums[i] == 1) currentOnes++;
        }

        int maxOnes = currentOnes;

        for(int i = k; i < nums.size(); i++){
            if(nums[i] == 1) currentOnes++;
            if(nums[i - k] == 1) currentOnes--;
            maxOnes = max(maxOnes, currentOnes);
        }

        res = k - maxOnes;

        return res;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
