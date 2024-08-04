#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int guess = 0;
	for(int i = 1; i*i <= n; i++)
	{
		guess = i;
	}
	cout<<guess;
}
