class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxRow = -1;
        int maxCount = 0;

        for (int i = 0; i < arr.size(); ++i) {
            int count = 0;
            for (int j = 0; j < arr[0].size(); ++j) {
                if (arr[i][j] == 1) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }
        return maxRow;
    }
};

