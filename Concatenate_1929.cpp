#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main() {
    Solution trail1;
    vector<int> inputVector = {1, 2, 3};
    
    vector<int> concatenatedVector = trail1.getConcatenation(inputVector);
    
    cout << "Concatenated vector: ";
    for (int num : concatenatedVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}