#include <iostream>
#include <vector>
using namespace std;

int pivotInteger(int n) {
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        nums[i] = i + 1;
    }

    // prefix sum
    for(int i = 1; i<n; i++){
        nums[i] = nums[i] + nums[i-1];
    }

    for(int i = 0; i<n; i++){
        if(2 * (nums[i] - nums[0]) == nums[n-1] + i + 1){
            return i+1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int pivotIndex = pivotInteger(n);
    if (pivotIndex != -1) {
        cout << "The pivot integer is at index " << pivotIndex << endl;
    } else {
        cout << "No pivot integer found." << endl;
    }
    return 0;
}
