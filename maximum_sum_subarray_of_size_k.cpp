#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxSubarray(vector<int> &nums, int k){
    int first_idx = 0;
    int last_idx = k - 1;
    int n = nums.size();

    int sum = 0;
    for(int i = 0; i<k; i++){
        sum += nums[i];
    }
    int currSum = sum;
    int maxIdx = k-1;
    int max_sum = INT_MIN;
    while(last_idx < n){
        currSum = currSum - nums[first_idx] + nums[last_idx];
        cout<<currSum<<endl;
        if(currSum > max_sum){
            max_sum = currSum;
            maxIdx = first_idx;
        }
        first_idx++;
        last_idx++;
    }

    return maxIdx + 1;
}

int main(){
    vector<int> nums = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int k = 4;
    cout<<maxSubarray(nums, k);
}