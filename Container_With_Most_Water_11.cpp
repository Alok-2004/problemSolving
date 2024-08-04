#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> &a)
{
	for(int i = 0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
}

int max_water(vector<int> &a)
{
	int n = a.size();
	int left = 0; // starting element
	int right = n-1; // last element
	int paani = 0;
	
	while(left<right)
	{
		int current_paani = min(a[right], a[left]) * (right - left);
		paani = max(current_paani, paani);
		
		if(a[left] < a[right])   left++;
		else   right--;
	}
	
	return paani;
}

int main()
{
	vector<int> height;
	
	height.push_back(2);
	height.push_back(3);
	height.push_back(2);
	height.push_back(6);
	height.push_back(8);
	height.push_back(1);
	height.push_back(0);
	
	cout<<"[ ";
	display(height);
	cout<<" ]"<<endl;
	cout<<max_water(height);
}

