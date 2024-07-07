#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long newBakery(int num, int fixed, int modified) {
    if (fixed >= modified) {
        return static_cast<long long>(fixed) * num;
    } else {
        int n = modified - (fixed + 1) + 1;
        if (n >= num) {
            long long profit = (static_cast<long long>(num) * (2 * modified - num + 1)) / 2;
            return profit;
        } else if (n > 0 && num > n) {
            int x = num - n;
            long long profit = (static_cast<long long>(n) * (2 * modified - (n - 1))) / 2;
            profit += x * fixed;
            return profit;
        } else {
            int profit = fixed * num;
            return profit;
        }
    }
}

int main() {
    int num, fixed, modified;
    // cin >> num >> fixed >> modified;
//     long long res = newBakery(num, fixed, modified);
    long long res = newBakery(1000, 1, 1000);
    cout << res;

}

