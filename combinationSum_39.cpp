#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void combination(vector<int>& candidates, vector<int>& current, vector<vector<int>>& result, int target, int idx) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (target < 0 || idx >= candidates.size()) {
            return;
        }
        
        // Include current element
        current.push_back(candidates[idx]);
        combination(candidates, current, result, target - candidates[idx], idx);
        current.pop_back();
        
        // Exclude current element
        combination(candidates, current, result, target, idx + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        combination(candidates, current, result, target, 0);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    cout << "Result:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
