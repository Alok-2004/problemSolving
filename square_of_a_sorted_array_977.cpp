#include<iostream>
#include<vector>
#include<algorithm>

// Time complexity is in order of O(n) and space complexity is also in order of O(n)

using namespace std;

vector<int> squarseAndSorted(vector<int> &nums){
    vector<int> res(nums.size());

    int i = nums.size() - 1;
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int left_square = nums[left] * nums[left];
        int right_square = nums[right] * nums[right];
        
        if(left_square >= right_square){
            res[i] = left_square;
            left++;
        }else{
            res[i] = right_square;
            right--;
        }

        i--;
    }

    return res;
}

int main(){
    vector<int> nums = {-3, -2, -1, 2, 3, 4, 5};

    cout<<"Original Array: "<<endl;
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    vector<int>sqaure_nums = squareAndSorted(nums);

    for(int i = 0; i<sqaure_nums.size(); i++){
        cout<<sqaure_nums[i]<<" ";
    }

}