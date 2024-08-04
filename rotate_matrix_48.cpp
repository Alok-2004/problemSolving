#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix)
{
    int m = matrix.size(); // row
    // transpose
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // reverse each row
    for (int j = 0; j < m; j++) // here  j is row number
    {
        int lo = 0;
        int hi = m - 1;
        while (lo <= hi)
        {
            int temp = matrix[j][lo];
            matrix[j][lo] = matrix[j][hi];
            matrix[j][hi] = temp;
            lo++;
            hi--;
        }
    }

    // Return the rotated matrix
    return matrix;
}

int main()
{
    vector<vector<int>> v = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    
    vector<vector<int>> rotated = rotate(v);

    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[i].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
