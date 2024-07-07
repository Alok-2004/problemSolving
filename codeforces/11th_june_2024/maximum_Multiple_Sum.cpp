#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<long long> results;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        long long max_sum = 0;
        long long optimal_x = 2;

        for (int x = 2; x <= n; ++x) {
            int k = n / x;
            long long sum = x * k * (k + 1) / 2;
            
            if (sum > max_sum) {
                max_sum = sum;
                optimal_x = x;
            }
        }

        results.push_back(optimal_x);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}

