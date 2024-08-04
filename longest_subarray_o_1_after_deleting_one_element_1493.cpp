#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int flip = 1;
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxi = INT_MIN;


            while (j < nums.size())
            {
                if (nums[j] == 1)
                {
                    ans++;
                    j++;
                }
                else if (nums[j] == 0 && flip > 0)
                {
                    ans++;
                    flip--;
                    j++;
                }
                else
                {
                    while (flip == 0)
                    {
                        if (nums[i] == 1)
                        {
                            i++;
                            ans--;
                        }
                        else
                        {
                            i++;
                            flip++;
                            ans--;
                        }
                    }
                }
                maxi = max(maxi ,ans);
            }
        return maxi - 1;
    }
};