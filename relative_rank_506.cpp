#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int siz = score.size();

        vector<vector<int>> temp(siz, vector<int>(2, 0));
        for(int i = 0; i<siz; i++){
            temp[i][0] = score[i];
            temp[i][1] = i;
        }

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        vector<string>ans(siz);

        for(int i = 0; i<siz; i++){
            if(i == 0)  ans[temp[0][1]] = "Gold Medal";
            else if(i == 1) ans[temp[1][1]] = "Silver Medal";
            else if(i == 2)  ans[temp[2][1]] = "Bronze Medal";
            else   ans[temp[i][1]] = to_string(i+1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> scores = {5, 10, 8, 4, 6};
    vector<string> result = s.findRelativeRanks(scores);

    for(const string& rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}

