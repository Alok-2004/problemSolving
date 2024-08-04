#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int min_len = INT_MAX;
    int sum = 0;
    int i=0, j=0, len;

    while( j < n ){
        sum += nums[j];
        while(sum>=target){
            len = j - i + 1;
            min_len = min(min_len, len);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    if(min_len == INT_MAX)  return 0;
    return min_len;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int ans = minSubArrayLen(target, nums);
    cout<<ans;

}
