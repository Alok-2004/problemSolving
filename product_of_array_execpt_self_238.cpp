#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    // arr = 1, 2, 3, 4
    // pre = 1, 1, 2, 6
    // suffix = 24, 12, 4, 1
    // ans = 24, 12, 8, 6
    vector<int> pre(n, 1);    // Initialize pre with 1
    vector<int> suffix(n, 1); // Initialize suffix with 1

    // Calculate prefix product
    for (int i = 1; i < n; i++)   pre[i] = pre[i - 1] * nums[i - 1];

    // Calculate suffix product
    for (int i = n - 2; i >= 0; i--)  suffix[i] = suffix[i + 1] * nums[i + 1];

    // Calculate final result
    vector<int> ans(n);
    for (int i = 0; i < n; i++)  ans[i] = suffix[i] * pre[i];

    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
