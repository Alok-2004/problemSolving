#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums;
    
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);

    int n = nums.size();

    for(int i = 0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }

    cout<<endl;

    int ones = 0;
    int zos = 0;
    int twos = 0;

    for(int i = 0; i<n; i++)
    {
        if(nums[i] == 1) ones++;
        else if(nums[i] == 0) zos++;
        else twos++;
    }

    for(int i = 0; i<n; i++)
    {
        if(i<zos) nums[i] = 0;
        else if(i<(zos+ones)) nums[i] = 1;
        else nums[i] = 2;
    }
    for(int i = 0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}