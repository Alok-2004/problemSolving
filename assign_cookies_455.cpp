#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    int n = g.size(); // i is the greed factor
    int m = s.size(); // j is the size of the cookie

    sort(g.begin(), g.end()); // 7, 8, 9, 10
    sort(s.begin(), s.end()); // 5, 6, 7, 8

    // We can assign the cookie j to the child i, and the child i will be content.
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (s[j] >= g[i])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    // Example usage
    vector<int> g = {7, 8, 9, 10};
    vector<int> s = {5, 6, 7, 8};
    
    int result = findContentChildren(g, s);
    cout << "Content children: " << result << endl;

    return 0;
}
