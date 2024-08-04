#include <vector>
#include <algorithm> // for max function
using namespace std;

vector<long long> findPrefixScore(vector<int>& nums) {
    int n = nums.size();
    vector<long long> cnvr(n, 0);
    cnvr[0] = 2LL * nums[0];
    int maximum = nums[0];

    for (int i = 1; i < n; i++) {
        maximum = max(maximum, nums[i]);
        cnvr[i] = cnvr[i - 1] + nums[i] + maximum;
    }

    return cnvr;
}

int main() {
    vector<int> nums = {2,3,7,5,10};
    vector<long long> prefixScores = findPrefixScore(nums);

    for (int i = 0; i < prefixScores.size(); i++) {
        cout << prefixScores[i] << " ";
    }

    return 0;
}
