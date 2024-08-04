#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& fAns, size_t idx) {
        if (idx == nums.size()) {
            fAns.push_back(ans);
            return;
        }

        helper(nums, ans, fAns, idx + 1);
        ans.push_back(nums[idx]);
        helper(nums, ans, fAns, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> fAns;
        helper(nums, ans, fAns, 0);
        return fAns;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        if (!result[i].empty()) {
            cout << result[i][0];
            for (size_t j = 1; j < result[i].size(); ++j) {
                cout << ", " << result[i][j];
            }
        }
        cout << "]" << endl;
    }
    return 0;
}

