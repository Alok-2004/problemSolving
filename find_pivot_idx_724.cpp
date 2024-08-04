#include<iostream>
#include<vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 0);
    pre[0] = nums[0];
    for(int i = 1; i<n; i++){
        pre[i] = pre[i-1] + nums[i];
    }
    cout<<endl;

    for(int i = 0; i<n - 1; i++){
        if( 2 * pre[i] == (pre[n-1]- nums[i+ 1]) ){
            return i + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout<<pivotIndex(nums);
}