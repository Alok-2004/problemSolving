#include<iostream>
#include<vector>
using namespace std;

// array = {1, 4, 5, 2, 3, 7, 6}
//prefixSum = {1, 5, 10, 12, 15, 22, 28}

//M1 no. of operations = 1+2+3+4+..n = O(n^2)
// Single pass O(n)
/*
    int n = nums.size();
    vector<int>run(n);
    run[0] = nums[0];
    for(int i = 1; i<n; i++){
        run[i] = run[i - 1] + nums[i];
    }
    return run;
*/
vector<int> runningSum(vector<int>&nums){
    int n = nums.size();
    vector<int>run(n);
    run[0] = nums[0];
    for(int i = 1; i<n; i++){
        run[i] = run[i - 1] + nums[i];
    }
    return run;
}

int main(){
    vector<int> nums = {2, 13 ,4, 5, 6, 7, 10};
    
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
 
    cout<<endl;
    
    vector<int> res = runningSum(nums);


    for (size_t i = 0; i < nums.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    
}