#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ninv) {
    vector<vector<int>> ans;
    int start = ninv[0], end = ninv[1];
    bool inserted = false;

    for (int i = 0; i < inv.size(); i++) {
        int cstart = inv[i][0], cend = inv[i][1];

        if (cend < start || inserted) {
            ans.push_back({cstart, cend});
            continue;
        }

        start = min(start, cstart);

        if (end < cstart) {
            ans.push_back({start, end});
            ans.push_back({cstart, cend});
            inserted = true;
            continue;
        }

        if (end <= cend) {
            ans.push_back({start, cend});
            inserted = true;
        }
    }

    if (!inserted) {
        ans.push_back({start, end});
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);

    cout << "Result:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
