#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int check = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i]) {
            check = i;
            break;
        }
    }
    return check;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}
