// Time complexity is in order of nlogn which can be improved

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)  return nums[0];
        return nums[nums.size() / 2];

        /*
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        
        if (n == 1) {
            return nums[0];
        }
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            
            if (count > n / 2) {
                return nums[i];
            }
        }
        
        return -1; // No majority element
    }
    */
    }
};

int main() 
{
    Solution solution;

    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majority = solution.majorityElement(nums);
    
    if (majority != -1) 
    {
        cout << "The majority element is: " << majority << endl;
    }
    else 
    {
        cout << "There is no majority element." << endl;
    }

    return 0;
}
