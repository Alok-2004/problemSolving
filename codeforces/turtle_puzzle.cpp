#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>

using namespace std;

int turtlePuzzle(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end(), std::greater<int>());
    
    cout<<"Sorted array:";
    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    int starting_idx = -1;
    int ending_idx = -1;
    vector<int> prefix_sum(n);
    prefix_sum[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        prefix_sum[i] = prefix_sum[i + 1] + nums[i];
        if(prefix_sum[i + 1] > prefix_sum[i]){
            if(starting_idx == -1)  starting_idx = i;
        }
        if(prefix_sum[i] > prefix_sum[i + 1]){
            if(starting_idx != -1 && ending_idx == -1)  ending_idx = i + 1;
        }
    }

    prefix_sum[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        if(i == starting_idx){
            prefix_sum[i] = prefix_sum[i + 1] + abs(nums[i]);
            starting_idx++;    
        }
    }

    return prefix_sum[0];
}

int main(){
    int n ;
    cin>>n;

    vector<int> nums = {-2 ,3 ,-3};
    cout<<"Original array:";
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    turtlePuzzle(nums);
    return 0;
}
