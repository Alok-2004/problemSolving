/*
Q2. Find the Power of K-Size Subarrays II
You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
Its maximum element if all of its elements are consecutive and sorted in ascending order.
You need to find the power of all subarrays of nums of size k.
Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        queue<int>q;
        if( k == 1) return nums;
        vector<int> res(nums.size() - k + 1, -1);
        for (int i = 0; i <= nums.size() - k; i++) {
            bool flag = true;
            if( !q.empty() ){
                if(nums[i+k-1] != q.front()+1){
                    flag = false;
                }
                q.pop(); 
            }
            else{
                for (int j = 1; j < k; j++) {
                    if (nums[i + j] != nums[i] + j) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                res[i] = nums[i + k - 1];
                q.push(res[i]);
            }
        }
        return res;
    }
};

