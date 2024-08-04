// in question number 88 start from greatest value and assign i j k the last index of respective vector

#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &a)
{
    for(int i = 0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
}

vector<int> merge(vector<int>& arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> res(m + n);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            res[k] = arr1[i];
            i++;
        }
        else
        {
            res[k] = arr2[j];
            j++;
        }
        k++;
    }

    
    while (i < n)
    {
        res[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m)
    {
        res[k] = arr2[j];
        j++;
        k++;
    }

    return res;
}

int main()
{
    vector<int> arr1;
    arr1.push_back(2);
    arr1.push_back(4);
    arr1.push_back(7);
    arr1.push_back(9);
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(28);

    display(arr1);
    cout<<endl;

    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(5);
    arr2.push_back(6);
    arr2.push_back(8);

    display(arr2);
    cout<<endl;

    vector<int> v = merge(arr1, arr2);
    display(v);
    return 0;
}