#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    int idx = -1;
    //1) finding pivot index
    for(int i = n-2; i>=0; i--)// starting fromo second last index
    {
        if(nums[i] < nums[i+1])
        {
            idx = i;
            break;
        }
    }

    if(idx == -1)
    {
        reverse(nums.begin(),nums.end());
    }

    // 2) sorting/reverse after pivot
    reverse(nums.begin()+idx+1, nums.end());
    
    // Find the just greater element
    int j = -1;
    for(int i = idx+1; i<n; i++)
    {
        if(nums[i] > nums[idx])
        {
            j = i;
            break;
        }
    }

    // 4) swapping idx and idx + 1
    int temp = nums[idx];
    nums[idx] = nums[j];
    nums[j] = temp;
}

void display(vector<int> &nums)
{
    for(int i = 0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    //nums.push_back(6);

    display(nums);
    cout<<endl;

    nextPermutation(nums);
    display(nums);
}