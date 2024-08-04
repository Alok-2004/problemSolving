#include<iostream>
#include<vector>

using namespace std;

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
