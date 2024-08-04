#include<vector>
#include<iostream>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    int i = 0;
	    while (i < nums.size()) {
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        } else {
            i++;
        }
    }

    for (int i = nums.size() - 1; i >= 0 ; i--) {
        if (nums[i] != i + 1) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

int main(){
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int>result = findDuplicate(nums);
	return 0;
}
