/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; i++) {
            k[i] = min({k[t2] * 2, k[t3] * 3, k[t5] * 5});
            if (k[i] == k[t2] * 2) t2++;
            if (k[i] == k[t3] * 3) t3++;
            if (k[i] == k[t5] * 5) t5++;
        }
        return k[n - 1];
    }
};

int main() {
    int m;
    cin >> m;
    Solution s;
    cout << s.nthUglyNumber(m);
}
