#include <iostream>
#include <vector>
using namespace std;

bool canShower(int n, int s, int m, const vector<pair<int, int>>& intervals) {
    if (intervals.empty() && s <= m) return true;
    if (intervals.front().first >= s) return true;
    
    for (int i = 1; i < n; ++i) {
        int freeTime = intervals[i].first - intervals[i - 1].second;
        if (freeTime >= s) return true;
    }
    
    if (m - intervals.back().second >= s) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        
        if (canShower(n, s, m, intervals)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

