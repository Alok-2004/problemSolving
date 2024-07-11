#include <bits/stdc++.h>
using namespace std;

int angryMonk(priority_queue<int> &pq) {
    int breaking = 0;
    int num = 0;
    int ones = 0;
    pq.pop();
    while (!pq.empty()) {
        if (pq.top() != 1) {
            breaking += pq.top() - 1;
            pq.pop();
            num ++;
        } else {
            ones++;
            pq.pop();
        }
    }
    if(breaking > 0) return ones + 2 * breaking + num;
    else return ones;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            int j;
            cin >> j;
            pq.push(j);
        }
        cout << angryMonk(pq) << endl;
    }
    return 0;
}

