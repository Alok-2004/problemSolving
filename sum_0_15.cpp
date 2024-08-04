
// Issue with uniqueness of the vectors in result and also its brute force(naive)
/*
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) 
        {
            for (int j = i + 1; j < n - 1; j++) 
            {
                for (int k = j + 1; k < n; k++) 
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) 
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        result.push_back(triplet);
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // Skip duplicate i values to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int lo = i + 1;
        int hi = n - 1;

        while (lo < hi)
        {
            int current = nums[i] + nums[lo] + nums[hi];

            if (current == 0)
            {
                // Found a triplet with sum 0, add it to the result
                result.push_back({nums[i], nums[lo], nums[hi]});
                lo++;
                hi--;

                // Skip duplicate lo values to avoid duplicate triplets
                while (lo < hi && nums[lo] == nums[lo - 1])
                    lo++;

                // Skip duplicate hi values to avoid duplicate triplets
                while (lo < hi && nums[hi] == nums[hi + 1])
                    hi--;
            }
            else if (current > 0)
            {
                // Move hi pointer to reduce the sum
                hi--;
            }
            else
            {
                // Move lo pointer to increase the sum
                lo++;
            }
        }
    }
    return result;
}

int main() {
    // Example arrays
    vector<int> arr1 = {-1, 0, 1, 2, -1, -4};
    vector<int> arr2 = {-2, 0, 0, 2, 2};
    vector<int> arr3 = {3, 0, -2, -1, 1, 2};

    vector<vector<int>> result1 = threeSum(arr1);
    vector<vector<int>> result2 = threeSum(arr2);
    vector<vector<int>> result3 = threeSum(arr3);

    // Print the results
    cout << "Triplets in arr1 with sum 0:" << endl;
    for (vector<int>& triplet : result1) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }
    
    cout << "Triplets in arr2 with sum 0:" << endl;
    for (vector<int>& triplet : result2) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    cout << "Triplets in arr3 with sum 0:" << endl;
    for (vector<int>& triplet : result3) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}

