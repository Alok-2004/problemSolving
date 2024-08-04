#include<iostream>
#include<vector>

using namespace std;
/*
Time complexity is O(n)
vector<int> lastAndFirst(vector<int> &nums, int target)
{
	int n = nums.size();
	vector<int> result(2,-1);
	
	int lo = 0;
	int hi = n-1;
	
	while(lo<=hi)
	{
		if(nums[lo] == target && nums[hi] == target)
		{
			result[0] = lo;
			result[1] = hi;
			break;
		}
		else if(nums[lo] < target)
		{
			lo++;
		}
		else if(nums[hi] > target)
		{
			hi--;
		}
	}
	return result;
}
*/

vector<int> searchRange(vector<int>& nums, int target) 
{
       int n = nums.size();
       vector<int> result(2, -1);
        
        // For first position
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    result[0] = mid;
                    break;
                }
                else hi = mid - 1;
            }
            else if (nums[mid] > target) hi = mid - 1;
            else  lo = mid + 1;
        }

        // For last position
        int lo1 = 0;
        int hi1 = n - 1;

        while (lo1 <= hi1)
        {
            int mid = lo1 + (hi1 - lo1) / 2;
            if (nums[mid] == target)
            {
                if (mid == n - 1 || nums[mid + 1] != target)
                {
                    result[1] = mid;
                    break;
                }
                else lo1 = mid + 1;
            }
            else if (nums[mid] > target)  hi1 = mid - 1;
            else  lo1 = mid + 1;
        }
        return result;
    }
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(10);
	
	int target = 4;	
	vector<int> result = lastAndFirst(nums, target);
	
	cout << "Lower Bound: " << result[0] << endl;
    cout << "Upper Bound: " << result[1] << endl;

	return 0;
}
