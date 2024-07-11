#include <bits/stdc++.h>
using namespace std;

bool canReachRightBank(int n, int m, int k, const string &a) {
    queue<pair<int, int> > q;
    vector<bool> visited(n + 2, false);
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        auto [pos, swum] = q.front();
        q.pop();

        if (pos == n + 1) {
            return true;
        }

        if (pos == 0 || a[pos - 1] == 'L') {
            for (int i = 1; i <= m; ++i) {
                int nextPos = pos + i;
                if (nextPos <= n + 1 && !visited[nextPos]) {
                    if (nextPos == n + 1 || a[nextPos - 1] != 'C') {
                        q.push({nextPos, swum});
                        visited[nextPos] = true;
                    }
                }
            }
        }

        if (pos > 0 && pos <= n && a[pos - 1] == 'W') {
            int nextPos = pos + 1;
            if (nextPos <= n + 1 && !visited[nextPos]) {
                if (nextPos == n + 1 || a[nextPos - 1] != 'C') {
                    if (swum + 1 <= k) {
                        q.push({nextPos, swum + 1});
                        visited[nextPos] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a;
        cin >> a;

        if (canReachRightBank(n, m, k, a)) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }
    return 0;
}

