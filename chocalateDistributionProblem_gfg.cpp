class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        if (m == 0 || n == 0) return 0;
        if (n < m) return -1;

        sort(a.begin(), a.end());
        long long min_diff = LLONG_MAX;

        for (long long i = 0; i + m - 1 < n; ++i) {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff) min_diff = diff;
        }
        
        return min_diff;
    }
};
