// not successfull

#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int i = 0;
    long long count = 0;
    long long three_count = 0;
    long long n = nums.size();
    
    for (int j = 0; j < n; j++) {
        if (nums[j] == 3) three_count++;

        while (three_count > k) {
            if (nums[i] == 3) three_count--;
            i++;
        }

        if (three_count == k) {
            count += (j - i + 1);
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1,3,2,3,3}; // Example input
    int k = 2; // Example k value
    long long result = countSubarrays(nums, k);
    cout << "Count of subarrays with exactly " << k << " occurrences of 3: " << result << endl;
    return 0;
}
