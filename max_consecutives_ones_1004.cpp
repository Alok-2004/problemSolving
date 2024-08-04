#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

    int longestOnes(vector<int>& nums, int k) {
        
        int flip = k;
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
        return maxi;
    }

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = longestOnes(nums, k);
    cout<<ans;
}