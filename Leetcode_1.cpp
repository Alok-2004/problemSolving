// Array method

// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of element: ";
//     cin>>n;

//     int nums[n];
    
//     for(int i = 0; i<n; i++)
//     {
//         cin>>nums[i];
//     }

//     int target;
//     cout<<"Target: ";
//     cin>>target;

//     for(int i = 0; i<n; i++)
//     {
//         for(int j = i+1; j<n; j++)
//         {
//             if( nums[i] + nums[j] == target)
//             {
//                 cout<<i<<", "<<j<<endl;
//             }
//         }
//     }
//     return 0;
// }

// Vector method

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int x;
    cout<<"Traget: ";
    cin>>x;

    int n;
    cout<<"Size of array: ";
    cin>>n;

    vector<int>num;

    cout<<"Enter the elements"<<endl;
    for(int i = 0; i<n; i++)
    {
    	int q;
    	cin>>q;
    	num.push_back(q);
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(num[j] + num[i] == x){
				cout<<"["<<i<<","<<j<<"]"<<endl;
			}
		}
	}
	return 0;
}
