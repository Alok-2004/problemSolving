#include <bits/stdc++.h>
using namespace std;

int maxBananas(int a, int b, int c) {
    for (int i = 0; i < 5; i++) {
        if (a <= b && a <= c) a++;
		else if (b <= a && b <= c) b++;
        else   c++;
    }
    return a * b * c;
}

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << maxBananas(a, b, c) << endl;
        n--;
    }
    return 0;
}

