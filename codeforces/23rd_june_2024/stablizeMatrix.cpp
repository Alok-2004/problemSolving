#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to stabilize the matrix
void stabilizeMatrix(vector<vector<int>>& matrix, int n, int m) {
    while (true) {
        int max_val = -1;
        int max_i = -1, max_j = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isGreater = true;
                if (i > 0 && matrix[i][j] <= matrix[i-1][j]) isGreater = false;
                else if (i < n-1 && matrix[i][j] <= matrix[i+1][j]) isGreater = false;
                else if (j > 0 && matrix[i][j] <= matrix[i][j-1]) isGreater = false;
                else if (j < m-1 && matrix[i][j] <= matrix[i][j+1]) isGreater = false;

                if (isGreater) {
                    if (matrix[i][j] > max_val) {
                        max_val = matrix[i][j];
                        max_i = i;
                        max_j = j;
                    } else if (matrix[i][j] == max_val) {
                        if (i < max_i || (i == max_i && j < max_j)) {
                            max_i = i;
                            max_j = j;
                        }
                    }
                }
            }
        }

        if (max_val == -1) {
            break;
        }

        matrix[max_i][max_j]--;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        stabilizeMatrix(matrix, n, m);

        for (const auto& row : matrix) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    return 0;
}