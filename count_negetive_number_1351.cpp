#include<iostream>
#include<vector>

using namespace std;

int countNegatives(vector<vector<int> >& grid){
    int m = grid.size();  // row
    int n = grid[0].size(); // column
    
    int i =  0;  // row
    int j = n - 1; // coloumn
    int count = 0;
    while( i < m && j >= 0){
        if(grid[i][j] < 0){
            // All rows from the current row (i) to the last row (m-1) in this column contain negative numbers.
            count += m - i; 
            j--;
        }else{
            i++;
        }
    }
    return count;
}

int main(){
    vector<vector<int> > grid = { {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3} };
    
    int negatives = countNegatives(grid);
    cout << "Number of negative numbers: " << negatives << endl;
    
    return 0;
}

