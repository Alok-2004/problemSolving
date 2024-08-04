#include<iostream>
#include<vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k){
    if(k <= 1)  return 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int product = 1;

    while(j < nums.size()){

        product *= nums[j];
        
        while( product >= k){
            count += j - i;
            product /= nums[i];
            i++;
        }
        j++;
    }    

    while( i < nums.size()){
            count += j - i;
            // cout<<j - i<<" ,";
            product /= nums[i];
            i++;
        }
    return count;
}


int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;
    cout<< numSubarrayProductLessThanK(nums, k);
}