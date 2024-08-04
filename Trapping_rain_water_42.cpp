#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int>& a)
{
    for(int i = 0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
}

int trap(vector<int>& height)
{
    int n = height.size();
    
    //Prev greatest element
    vector<int> prev(n);
    prev[0] = -1;
    int max = height[0];
    for(int i = 1; i<n; i++)
    {
        prev[i] = max;
        if(max<height[i])  max = height[i];
    }

    cout<<"Prev greatest element: ["; 
    display(prev);
    cout<<"]";
    cout<<endl;

    // next greatest element
    vector<int> next(n);
    next[n-1] = -1;
    max = height[n-1];
    for(int i = n-2; i>=0; i--)
    {
        next[i] = max;
        if(max<height[i]) max = height[i];
    }

    cout<<"Next max element: ["; 
    display(next);
    cout<<"]";
    cout<<endl;

    // Min of next and prev = prev as mini
    for(int i = 0; i<n; i++)
    {
        prev[i] = min(prev[i],next[i]);
    }

    cout<<"Minimum: ["; 
    display(prev);
    cout<<"]";
    cout<<endl;

    // calculating water 
    int water = 0;
    for(int i = 1; i<n-1; i++)
    {
        if(height[i] < prev[i])
        {
            water = water + prev[i] - height[i]; 
        }
    }

    return water;
}

int main()
{
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);

    cout<<"Height: ["; 
    display(height);
    cout<<"]";
    cout<<endl;
    
    cout<<trap(height);
}