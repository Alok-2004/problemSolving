#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//method 2
/*
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    int max_element = INT_MIN;
    for(int i = 0 ; i<nums.size(); i++){
        max_element = max(nums[i], max_element);
    }
    vector<int> freq(max_element + 1, 0);

    for(int i = 0; i<nums.size(); i++){
        freq[nums[i]]++;
    }
    int maximum_count = INT_MIN;
    for(int i = 0; i < freq.size(); i++){
        maximum_count = max(maximum_count, freq[i]);
    }

    int num_of_times = 0;
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] == maximum_count) num_of_times++;
    }

    return num_of_times * maximum_count;

    }
};
};


*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = INT_MIN;
        if(nums.size() == 1)  return 1;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int c = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == nums[i]) {
                    c++;
                } else {
                    break;
                }
            }
            maxi = max(c, maxi);
        }

        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int c = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == nums[i]) {
                    c++;
                } else {
                    break;
                }
            }

            if(c == maxi) count++;
        }

        return count * maxi;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1};
    Solution s;
    cout << s.maxFrequencyElements(nums) << endl; // Output should be 4
    return 0;
}
