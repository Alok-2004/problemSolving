#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = (n / 10) + (n % 10);
        cout << res << endl;
    }
    return 0;
}

