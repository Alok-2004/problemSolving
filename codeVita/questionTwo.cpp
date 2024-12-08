#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> friendships(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        friendships[u].push_back(v);
        friendships[v].push_back(u);
    }
    cin >> k;

    vector<int> status(n, 1), new_status(n);
    int rostering = n, days = 1;
    while (rostering < k) {
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int friend_id : friendships[i]) count += status[friend_id];
            new_status[i] = (status[i] && count == 3) || (!status[i] && count < 3);
        }
        status = new_status;
        rostering += accumulate(status.begin(), status.end(), 0);
        ++days;
    }
    cout << days;
}

