#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void lexicographically_smallest_string(int t, vector<pair<pair<int, int>, pair<string, pair<vector<int>, string>>>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first.first;
        int m = test_cases[i].first.second;
        string s = test_cases[i].second.first;
        vector<int> ind = test_cases[i].second.second.first;
        string c = test_cases[i].second.second.second;

        vector<pair<int, char>> updates;
        for (int j = 0; j < m; ++j) {
            updates.push_back({ind[j], c[j]});
        }

        sort(updates.begin(), updates.end());

        for (const auto& update : updates) {
            s[update.first - 1] = update.second;
        }

        cout << s << endl;
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<pair<int, int>, pair<string, pair<vector<int>, string>>>> test_cases(t);

    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ind(m);
        for (int j = 0; j < m; ++j) {
            cin >> ind[j];
        }
        string c;
        cin >> c;
        test_cases[i] = {{n, m}, {s, {ind, c}}};
    }

    lexicographically_smallest_string(t, test_cases);

    return 0;
}
