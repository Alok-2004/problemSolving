#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    int n = queries.size();
    vector<int> ans(n);

    for(int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + nums[i - 1];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] <= queries[i]) {
                ans[i] = j + 1;
            } else {
                break;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> queries = {3, 7, 10, 12};

    vector<int> result = answerQueries(nums, queries);

    cout << "Result:";
    for(int i = 0; i < result.size(); i++) {
        cout << " " << result[i];
    }
    cout << endl;

    return 0;
}
