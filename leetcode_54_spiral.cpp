#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m;
    cout << "Enter the rows of matrix: ";
    cin >> m;

    int n;
    cout << "Enter the cols of the matrix: ";
    cin >> n;

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int minr = 0, minc = 0;
    int maxr = m - 1, maxc = n - 1;
    while (minr <= maxr && minc <= maxc)
    {
        // going right
        for (int j = minc; j <= maxc; j++)
        {
            cout << arr[minr][j] << " ";
        }
        minr++;
		
		if(minr > maxr || minc > maxc)  break;
        // going down
        for (int i = minr; i <= maxr; i++)
        {
            cout << arr[i][maxc] << " ";
        }
        maxc--;

        if(minr > maxr || minc > maxc)  break;
		// going left
        for (int j = maxc; j >= minc; j--)
        {
            cout << arr[maxr][j] << " ";
        }
        maxr--;

        if(minr > maxr || minc > maxc)  break;
		// going up
        for (int i = maxr; i >= minr; i--)
        {
            cout << arr[i][minc] << " ";
        }
        minc++;
    }
    cout << endl;
}

