#include<iostream>
#include<vector>
using namespace std;
//Three pointer algorithm
void sortColors(vector<int>& nums) 
    {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid<=high)
    {
        if(nums[mid] == 2)
        {
            nums[mid] = nums[high];
            nums[high] = 2;
            high--;
        }

        else if(nums[mid] == 1)
        {
            mid++;
        }

        else
        {
            nums[mid] = nums[low];
            nums[low] = 0;
            mid++;
            low++;
        }
    }
	return;
    }

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);

	for(int i = 0; i<nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;

	sortColors(nums);

	for(int i = 0; i<nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
}
